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
  // Update Robot status from Paramater Server
   ros::param::set("/Robot_pos", "Start_Point");
  // Wait 5 sec for move_base action server to come up
  while(!ac.waitForServer(ros::Duration(5.0))){
    ROS_INFO("Waiting for the move_base action server to come up");
  }

  move_base_msgs::MoveBaseGoal goal_pickup;
  move_base_msgs::MoveBaseGoal goal_dropoff;
  move_base_msgs::MoveBaseGoal goal_pickup1;
  move_base_msgs::MoveBaseGoal goal_pickup2;
  move_base_msgs::MoveBaseGoal goal_pickup3;
  // set up the frame parameters
  goal_pickup.target_pose.header.frame_id = "map";
  goal_pickup.target_pose.header.stamp = ros::Time::now();

  goal_dropoff.target_pose.header.frame_id = "map";
  goal_dropoff.target_pose.header.stamp = ros::Time::now();

  goal_pickup1.target_pose.header.frame_id = "map";
  goal_pickup1.target_pose.header.stamp = ros::Time::now();
  goal_pickup2.target_pose.header.frame_id = "map";
  goal_pickup2.target_pose.header.stamp = ros::Time::now();
  goal_pickup3.target_pose.header.frame_id = "map";
  goal_pickup3.target_pose.header.stamp = ros::Time::now();
  // Define a position and orientation for the robot to reach
  goal_pickup.target_pose.pose.position.x = 0.214;
  goal_pickup.target_pose.pose.orientation.w = 0.0947;
  goal_pickup.target_pose.pose.position.y = 9.5353;

  goal_dropoff.target_pose.pose.position.x = 0.0;
  goal_dropoff.target_pose.pose.orientation.w = 0.0947;
  goal_dropoff.target_pose.pose.position.y = 0.0;

  goal_pickup1.target_pose.pose.position.x = -5.5123;
  goal_pickup1.target_pose.pose.orientation.w = 0.78855;
  goal_pickup1.target_pose.pose.position.y = 6.0847;

  goal_pickup2.target_pose.pose.position.x = 6.5995;
  goal_pickup2.target_pose.pose.orientation.w = 0.7576;
  goal_pickup2.target_pose.pose.position.y = 3.2613;

  goal_pickup3.target_pose.pose.position.x = -2.6729;
  goal_pickup3.target_pose.pose.orientation.w = 0.8916;
  goal_pickup3.target_pose.pose.position.y = -7.1982;
   // Send PickUp1 Goal location
  ROS_INFO("Sending PickUp1 goal");
  ac.sendGoal(goal_pickup);
  // Update Robot Status using paramter server
  ros::param::set("/Robot_pos", "In_Route");
  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached PickUp1 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "PickUp1");
  }
  else{
    ROS_INFO("Failed to Reach PickUp Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "Failed_to_reach_PickUp1");
    return 0;
  }
  //  Wait 5 seconds
  ros::Duration(5.0).sleep();

   // Send PickUp2 location
  ROS_INFO("Sending PickUp2 goal");
  ac.sendGoal(goal_pickup1);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached PickUp2 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "PickUp2");
  }
  else{
    ROS_INFO("Failed to Reach PickUp2 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "Failed_to_reach_PickUp2");
  }

   // Send PickUp3 location
  ROS_INFO("Sending PickUp3 goal");
  ac.sendGoal(goal_pickup2);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached PickUp3 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "PickUp3");
  }
  else{
    ROS_INFO("Failed to Reach PickUp3 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "Failed_to_reach_PickUp3");
  }

   // Send PickUp4 location
  ROS_INFO("Sending PickUp4 goal");
  ac.sendGoal(goal_pickup3);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached PickUp4 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "PickUp4");
  }
  else{
    ROS_INFO("Failed to Reach PickUp4 Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "Failed_to_reach_PickUp4");
  }

   // Send DropOff location
  ROS_INFO("Sending DropOff Position");
  ac.sendGoal(goal_dropoff);

  // Wait an infinite time for the results
  ac.waitForResult();

  // Check if the robot reached its goal
  if(ac.getState() == actionlib::SimpleClientGoalState::SUCCEEDED){
    ROS_INFO("Reached DropOff Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "DropOff");
  }
  else{
    ROS_INFO("Failed to Reach DropOff Position");
    // Update Robot Status using paramter server
    ros::param::set("/Robot_pos", "Failed_to_reach_DropOff");
  }
  return 0;
}