#!/bin/sh

# Deploy Turtlebot in my designed Gazebo World
xterm -e "export ROBOT_INITIAL_POSE='-x 0.0 -y 0.0 -Y 1.57079633' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find world)/compl_world.world" &
sleep 10

# Run slam_gmapping to perfrom SLAM
xterm -e "roslaunch wall_follower slam_gmapping.launch" &
sleep 5

# Rviz launcher file
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

# Manually control the robot with keyboard commands
xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"