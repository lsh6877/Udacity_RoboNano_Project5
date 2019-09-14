#!/bin/bash

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 10

xterm -e "roslaunch turtlebot_gazebo gmapping_demo.launch" &
sleep 3

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 3

xterm -e "roslaunch turtlebot_teleop keyboard_teleop.launch"
