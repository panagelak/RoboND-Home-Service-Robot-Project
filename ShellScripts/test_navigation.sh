#!/bin/sh

# Deploy Turtlebot in my designed Gazebo World  
xterm -e "export ROBOT_INITIAL_POSE='-x 0.0 -y 0.0 -Y 1.57' && roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(rospack find world)/compl_world.world" &
sleep 10

# amcl_demo to localize the robot with our generated map
xterm -e "roslaunch turtlebot_navigation amcl_demo.launch map_file:=$(rospack find world)/map.yaml" &
sleep 5

# Rviz launcher file
xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 5

