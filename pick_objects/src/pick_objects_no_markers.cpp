#include <ros/ros.h>
#include <move_base_msgs/MoveBaseAction.h>
#include <actionlib/client/simple_action_client.h>

// Define a client for to send goal requests to the move_base server through a SimpleActionClient
typedef actionlib::SimpleActionClient<move_base_msgs::MoveBaseAction> MoveBaseClient;

int main(int argc, char** argv){
  // Initialize the simple_navigation_goals node
  ros::init(argc, argv, "pick_objects");

  //tell the action client that we want to spin a thread by default
  MoveBaseClient ac("move_base", true);


  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal_pickup;
  move_base_msgs::MoveBaseGoal goal_dropoff;
  // set up the frame parameters
  goal_pickup.target_pose.header.frame_id = "map";
  goal_pickup.target_pose.header.stamp = ros::Time::now();

  goal_dropoff.target_pose.header.frame_id = "map";
  goal_dropoff.target_pose.header.stamp = ros::Time::now();
  // Define a position and orientation for the robot to reach
  goal_pickup.target_pose.pose.position.x = -3.83;
  goal_pickup.target_pose.pose.orientation.w = 0.947;
  goal_pickup.target_pose.pose.position.y = 8.144;

  goal_dropoff.target_pose.pose.position.x = -6.4629;
  goal_dropoff.target_pose.pose.orientation.w = 0.01;
  goal_dropoff.target_pose.pose.position.y = -5.1092;
   // Send PickUp Goal location
  ROS_INFO("Sending PickUp goal");
  ac.sendGoal(goal_pickup);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached PickUp Position");

  else
    ROS_INFO("Failed to Reach PickUp Position");

  //  Wait 5 seconds
  ros::Duration(5.0).sleep();

   // Send DropOff location
  ROS_INFO("Sending DropOff goal");
  ac.sendGoal(goal_dropoff);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED)
    ROS_INFO("Reached DropOff Position");

  else
    ROS_INFO("Failed to Reach DropOff Position");


  return 0;
}