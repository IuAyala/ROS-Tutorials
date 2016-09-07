#include "ros/ros.h"
#include "tutorial_1_pkg/demo_srv.h"
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char ** argv)
{
	// Initialize ros node
	ros::init(argc, argv, "demo_service_client");
	ros::NodeHandle n;
	
	// Define loop_rate and creating the ServerClient  
	ros::Rate loop_rate(10);
	ros::ServiceClient client = n.serviceClient<tutorial_1_pkg::demo_srv>("demo_service");
	
	// Spin until escape
	while(ros::ok())
	{
		tutorial_1_pkg::demo_srv srv;
		std::string ss = "Sending from here";
		srv.request.in = ss.c_str();
		
		// Call the server, kill the node otherwise
		if (client.call(srv))
		{
			ROS_INFO("From client [%s], Server says [%s]", srv.request.in.c_str(), srv.response.out.c_str() );
		}
		else
		{
			ROS_ERROR("Failed to call service");
			return 1;
		}
		ros::spinOnce();
		loop_rate.sleep();
	}
	return 0;
}
