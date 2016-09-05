#include "ros/ros.h"
#include "std_msgs/Int32.h"
#include <iostream>
#include "tutorial_1_pkg/demo_msg.h"
#include <sstream>
#include <string>

#include <typeinfo>

int main(int argc, char ** argv)
{
	// Initialize publisher
	ros::init(argc, argv, "demo_msg_publisher");

	//Create Node Object
	ros::NodeHandle node_obj;

	//Create publisher deffining the name of the topic and its buffer size
	ros::Publisher number_publisher = node_obj.advertise<tutorial_1_pkg::demo_msg>("/topic_msg", 10);
	
	//Define loop rate of publishing msgs
	ros::Rate loop_rate(10);
	
	int number_count = 0;
	std::string str1 = "Hello_World";
	
	while(ros::ok()){
		
		tutorial_1_pkg::demo_msg msg;
		
		// Fill number of the msg - fjñlisejafi
		msg.number = number_count;
		
		// Fill sting of the messages
		//char * char_ptr = new char [str1.length() + 1];
		//strcpy(char_ptr, str1.c_str());
		//msg.greeting = char_ptr;
		//delete [] char_ptr;
		
	    msg.greeting = str1.c_str();
		
		// For a message to be displayed with the argument %s has to be  of the type c_str()
		ROS_INFO("%d", msg.number);
		ROS_INFO("%s", str1.c_str() );
		ROS_INFO("%s", msg.greeting.c_str() );
		
		// Publish messages
		number_publisher.publish(msg);
		ros::spinOnce();
		loop_rate.sleep();
		++number_count;
	}
	return 0;
}
