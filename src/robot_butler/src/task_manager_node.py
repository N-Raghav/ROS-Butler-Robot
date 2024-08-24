#!/usr/bin/env python3

import rospy
from std_msgs.msg import String, Bool
from robot_butler.msg import Order, TaskStatus  
import time

current_task = None
orders_queue = []
task_in_progress = False
task_start_time = None
task_timeout = 30  

def initialize_node():
    rospy.init_node('task_manager_node', anonymous=True)

def order_callback(order_msg):
    global orders_queue
    rospy.loginfo(f"Received new order: {order_msg}")
    orders_queue.append(order_msg)
    rospy.loginfo(f"Current orders queue: {orders_queue}")

def task_status_callback(status_msg):
    global task_in_progress
    rospy.loginfo(f"Received task status: {status_msg.status}")
    if status_msg.status == "completed":
        task_in_progress = False
        rospy.loginfo("Task completed successfully.")
    elif status_msg.status == "timeout":
        task_in_progress = False
        rospy.loginfo("Task timed out, returning to home position.")
    elif status_msg.status == "cancelled":
        task_in_progress = False
        rospy.loginfo("Task was cancelled.")

def process_orders():
    global current_task, orders_queue, task_in_progress, task_start_time

    if not task_in_progress and orders_queue:
        current_task = orders_queue.pop(0)
        rospy.loginfo(f"Processing order: {current_task}")

        task_pub.publish(current_task)
        task_in_progress = True
        task_start_time = rospy.Time.now()


    if task_in_progress and (rospy.Time.now() - task_start_time).to_sec() > task_timeout:
        rospy.logwarn("Task timed out, returning to home position.")
        task_in_progress = False
        task_pub.publish("return_home")

if __name__ == '__main__':
    try:
        initialize_node()

        
        rospy.Subscriber('orders_topic', Order, order_callback)
        rospy.Subscriber('task_status_topic', TaskStatus, task_status_callback)

        
        task_pub = rospy.Publisher('movement_command_topic', String, queue_size=10)

        rospy.loginfo("Task Manager Node is running...")

        
        rate = rospy.Rate(10)  
        while not rospy.is_shutdown():
            process_orders()
            rate.sleep()

    except rospy.ROSInterruptException:
        rospy.loginfo("Task Manager Node terminated.")
