;; Auto-generated. Do not edit!


(when (boundp 'robot_butler::Order)
  (if (not (find-package "ROBOT_BUTLER"))
    (make-package "ROBOT_BUTLER"))
  (shadow 'Order (find-package "ROBOT_BUTLER")))
(unless (find-package "ROBOT_BUTLER::ORDER")
  (make-package "ROBOT_BUTLER::ORDER"))

(in-package "ROS")
;;//! \htmlinclude Order.msg.html


(defclass robot_butler::Order
  :super ros::object
  :slots (_table_number _order_id _status ))

(defmethod robot_butler::Order
  (:init
   (&key
    ((:table_number __table_number) 0)
    ((:order_id __order_id) 0)
    ((:status __status) "")
    )
   (send-super :init)
   (setq _table_number (round __table_number))
   (setq _order_id (round __order_id))
   (setq _status (string __status))
   self)
  (:table_number
   (&optional __table_number)
   (if __table_number (setq _table_number __table_number)) _table_number)
  (:order_id
   (&optional __order_id)
   (if __order_id (setq _order_id __order_id)) _order_id)
  (:status
   (&optional __status)
   (if __status (setq _status __status)) _status)
  (:serialization-length
   ()
   (+
    ;; uint32 _table_number
    4
    ;; uint32 _order_id
    4
    ;; string _status
    4 (length _status)
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _table_number
       (write-long _table_number s)
     ;; uint32 _order_id
       (write-long _order_id s)
     ;; string _status
       (write-long (length _status) s) (princ _status s)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _table_number
     (setq _table_number (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _order_id
     (setq _order_id (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; string _status
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _status (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;;
   self)
  )

(setf (get robot_butler::Order :md5sum-) "c9ac07ebf20335825ba32343d6e68824")
(setf (get robot_butler::Order :datatype-) "robot_butler/Order")
(setf (get robot_butler::Order :definition-)
      "uint32 table_number
uint32 order_id
string status


")



(provide :robot_butler/Order "c9ac07ebf20335825ba32343d6e68824")


