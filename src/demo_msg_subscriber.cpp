#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include "tutorial_1_pkg/demo_msg.h"
#include <string>

void msg_callback(const tutorial_1_pkg::demo_msg::ConstPtr& msg)
{
	ROS_INFO("Received [%d]", msg->number);
	std::string str1 = msg->greeting;
	ROS_INFO("Received geeting [%s]", str1.c_str() );
	ROS_INFO("Received geeting [%s]", msg->greeting.c_str() );
}

int main(int argc, char ** argv)
{
	ros::init(argc, argv, "demo_msg_subscriber");
	ros::NodeHandle node_obj;
	ros::Subscriber number_subscriber = node_obj.subscribe("/topic_msg", 10, msg_callback);
	ros::spin();
	return 0;
}
