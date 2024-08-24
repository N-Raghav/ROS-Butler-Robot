// Auto-generated. Do not edit!

// (in-package robot_butler.msg)


"use strict";

const _serializer = _ros_msg_utils.Serialize;
const _arraySerializer = _serializer.Array;
const _deserializer = _ros_msg_utils.Deserialize;
const _arrayDeserializer = _deserializer.Array;
const _finder = _ros_msg_utils.Find;
const _getByteLength = _ros_msg_utils.getByteLength;

//-----------------------------------------------------------

class Order {
  constructor(initObj={}) {
    if (initObj === null) {
      // initObj === null is a special case for deserialization where we don't initialize fields
      this.table_number = null;
      this.order_id = null;
      this.status = null;
    }
    else {
      if (initObj.hasOwnProperty('table_number')) {
        this.table_number = initObj.table_number
      }
      else {
        this.table_number = 0;
      }
      if (initObj.hasOwnProperty('order_id')) {
        this.order_id = initObj.order_id
      }
      else {
        this.order_id = 0;
      }
      if (initObj.hasOwnProperty('status')) {
        this.status = initObj.status
      }
      else {
        this.status = '';
      }
    }
  }

  static serialize(obj, buffer, bufferOffset) {
    // Serializes a message object of type Order
    // Serialize message field [table_number]
    bufferOffset = _serializer.uint32(obj.table_number, buffer, bufferOffset);
    // Serialize message field [order_id]
    bufferOffset = _serializer.uint32(obj.order_id, buffer, bufferOffset);
    // Serialize message field [status]
    bufferOffset = _serializer.string(obj.status, buffer, bufferOffset);
    return bufferOffset;
  }

  static deserialize(buffer, bufferOffset=[0]) {
    //deserializes a message object of type Order
    let len;
    let data = new Order(null);
    // Deserialize message field [table_number]
    data.table_number = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [order_id]
    data.order_id = _deserializer.uint32(buffer, bufferOffset);
    // Deserialize message field [status]
    data.status = _deserializer.string(buffer, bufferOffset);
    return data;
  }

  static getMessageSize(object) {
    let length = 0;
    length += _getByteLength(object.status);
    return length + 12;
  }

  static datatype() {
    // Returns string type for a message object
    return 'robot_butler/Order';
  }

  static md5sum() {
    //Returns md5sum for a message object
    return 'c9ac07ebf20335825ba32343d6e68824';
  }

  static messageDefinition() {
    // Returns full string definition for message
    return `
    uint32 table_number
    uint32 order_id
    string status
    
    
    `;
  }

  static Resolve(msg) {
    // deep-construct a valid message object instance of whatever was passed in
    if (typeof msg !== 'object' || msg === null) {
      msg = {};
    }
    const resolved = new Order(null);
    if (msg.table_number !== undefined) {
      resolved.table_number = msg.table_number;
    }
    else {
      resolved.table_number = 0
    }

    if (msg.order_id !== undefined) {
      resolved.order_id = msg.order_id;
    }
    else {
      resolved.order_id = 0
    }

    if (msg.status !== undefined) {
      resolved.status = msg.status;
    }
    else {
      resolved.status = ''
    }

    return resolved;
    }
};

module.exports = Order;
