#!/usr/bin/env python3
import rospy
from std_msgs.msg import String
from robot_butler.msg import Order

def order_callback(data):
    
    rospy.loginfo(f"Received new order: {data.data}")

    try:
        order_data = data.data.split()  # Assume order data is "Order for Table X"
        table_number = int(order_data[-1])
        
        if table_number in [1, 2, 3]:
            order = Order()
            order.table_number = table_number
            order.order_id = int(rospy.Time.now().to_sec())  
            order.status = "pending"
            order_pub.publish(order)
            rospy.loginfo(f"Order for Table {table_number} processed and added to queue.")
        else:
            rospy.logwarn(f"Invalid table number received: {table_number}")

    except ValueError as e:
        rospy.logerr(f"Error parsing order data: {e}")
        
rospy.init_node("orders_node",anonymous=True)

order_pub = rospy.Publisher('/order_queue', Order, queue_size=10)

rospy.Subscriber('/new_order', String, order_callback)



if __name__ == '__main__':
    try:
        rospy.spin()  
    except rospy.ROSInterruptException:
        rospy.loginfo("Order Processor Node has been shut down.")
