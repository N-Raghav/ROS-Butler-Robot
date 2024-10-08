// Generated by gencpp from file robot_butler/Order.msg
// DO NOT EDIT!


#ifndef ROBOT_BUTLER_MESSAGE_ORDER_H
#define ROBOT_BUTLER_MESSAGE_ORDER_H


#include <string>
#include <vector>
#include <memory>

#include <ros/types.h>
#include <ros/serialization.h>
#include <ros/builtin_message_traits.h>
#include <ros/message_operations.h>


namespace robot_butler
{
template <class ContainerAllocator>
struct Order_
{
  typedef Order_<ContainerAllocator> Type;

  Order_()
    : table_number(0)
    , order_id(0)
    , status()  {
    }
  Order_(const ContainerAllocator& _alloc)
    : table_number(0)
    , order_id(0)
    , status(_alloc)  {
  (void)_alloc;
    }



   typedef uint32_t _table_number_type;
  _table_number_type table_number;

   typedef uint32_t _order_id_type;
  _order_id_type order_id;

   typedef std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>> _status_type;
  _status_type status;





  typedef boost::shared_ptr< ::robot_butler::Order_<ContainerAllocator> > Ptr;
  typedef boost::shared_ptr< ::robot_butler::Order_<ContainerAllocator> const> ConstPtr;

}; // struct Order_

typedef ::robot_butler::Order_<std::allocator<void> > Order;

typedef boost::shared_ptr< ::robot_butler::Order > OrderPtr;
typedef boost::shared_ptr< ::robot_butler::Order const> OrderConstPtr;

// constants requiring out of line definition



template<typename ContainerAllocator>
std::ostream& operator<<(std::ostream& s, const ::robot_butler::Order_<ContainerAllocator> & v)
{
ros::message_operations::Printer< ::robot_butler::Order_<ContainerAllocator> >::stream(s, "", v);
return s;
}


template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator==(const ::robot_butler::Order_<ContainerAllocator1> & lhs, const ::robot_butler::Order_<ContainerAllocator2> & rhs)
{
  return lhs.table_number == rhs.table_number &&
    lhs.order_id == rhs.order_id &&
    lhs.status == rhs.status;
}

template<typename ContainerAllocator1, typename ContainerAllocator2>
bool operator!=(const ::robot_butler::Order_<ContainerAllocator1> & lhs, const ::robot_butler::Order_<ContainerAllocator2> & rhs)
{
  return !(lhs == rhs);
}


} // namespace robot_butler

namespace ros
{
namespace message_traits
{





template <class ContainerAllocator>
struct IsMessage< ::robot_butler::Order_<ContainerAllocator> >
  : TrueType
  { };

template <class ContainerAllocator>
struct IsMessage< ::robot_butler::Order_<ContainerAllocator> const>
  : TrueType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_butler::Order_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct IsFixedSize< ::robot_butler::Order_<ContainerAllocator> const>
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_butler::Order_<ContainerAllocator> >
  : FalseType
  { };

template <class ContainerAllocator>
struct HasHeader< ::robot_butler::Order_<ContainerAllocator> const>
  : FalseType
  { };


template<class ContainerAllocator>
struct MD5Sum< ::robot_butler::Order_<ContainerAllocator> >
{
  static const char* value()
  {
    return "c9ac07ebf20335825ba32343d6e68824";
  }

  static const char* value(const ::robot_butler::Order_<ContainerAllocator>&) { return value(); }
  static const uint64_t static_value1 = 0xc9ac07ebf2033582ULL;
  static const uint64_t static_value2 = 0x5ba32343d6e68824ULL;
};

template<class ContainerAllocator>
struct DataType< ::robot_butler::Order_<ContainerAllocator> >
{
  static const char* value()
  {
    return "robot_butler/Order";
  }

  static const char* value(const ::robot_butler::Order_<ContainerAllocator>&) { return value(); }
};

template<class ContainerAllocator>
struct Definition< ::robot_butler::Order_<ContainerAllocator> >
{
  static const char* value()
  {
    return "uint32 table_number\n"
"uint32 order_id\n"
"string status\n"
"\n"
;
  }

  static const char* value(const ::robot_butler::Order_<ContainerAllocator>&) { return value(); }
};

} // namespace message_traits
} // namespace ros

namespace ros
{
namespace serialization
{

  template<class ContainerAllocator> struct Serializer< ::robot_butler::Order_<ContainerAllocator> >
  {
    template<typename Stream, typename T> inline static void allInOne(Stream& stream, T m)
    {
      stream.next(m.table_number);
      stream.next(m.order_id);
      stream.next(m.status);
    }

    ROS_DECLARE_ALLINONE_SERIALIZER
  }; // struct Order_

} // namespace serialization
} // namespace ros

namespace ros
{
namespace message_operations
{

template<class ContainerAllocator>
struct Printer< ::robot_butler::Order_<ContainerAllocator> >
{
  template<typename Stream> static void stream(Stream& s, const std::string& indent, const ::robot_butler::Order_<ContainerAllocator>& v)
  {
    s << indent << "table_number: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.table_number);
    s << indent << "order_id: ";
    Printer<uint32_t>::stream(s, indent + "  ", v.order_id);
    s << indent << "status: ";
    Printer<std::basic_string<char, std::char_traits<char>, typename std::allocator_traits<ContainerAllocator>::template rebind_alloc<char>>>::stream(s, indent + "  ", v.status);
  }
};

} // namespace message_operations
} // namespace ros

#endif // ROBOT_BUTLER_MESSAGE_ORDER_H
