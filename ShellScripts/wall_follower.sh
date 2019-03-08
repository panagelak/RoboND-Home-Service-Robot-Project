#!/bin/sh

# Deploy Turtlebot in my designed Gazebo World
xterm -e "export ROBOT_INITIAL_POSE='-x 0.0 -y 2.0 -Y 1.57' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find world)/compl_world.world" &
sleep 10

# Run slam_gmapping to perfrom SLAM
xterm -e "roslaunch wall_follower slam_gmapping.launch" &
sleep 5

# Rviz launcher file
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

# Wall follower node to automatically traverse a close environment
xterm -e "rosrun wall_follower node"
