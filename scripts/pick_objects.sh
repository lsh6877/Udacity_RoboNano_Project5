#!/bin/bash

xterm -e "roslaunch turtlebot_gazebo turtlebot_world.launch world_file:=$(pwd)/../map/myworld.world" &
sleep 10

xterm -e "roslaunch turtlebot_gazebo amcl_demo.launch map_file:=$(pwd)/../map/my_map.yaml" &
sleep 2

xterm -e "roslaunch turtlebot_rviz_launchers view_navigation.launch" &
sleep 10

xterm -e "rosrun pick_objects pick_objects"

