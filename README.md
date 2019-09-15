## Udacity RoboNano Project5 : Home Service Robot

### Directory and packages description

```
    Udacity_RoboNano_Project5                          # Home Service Robot Project
    |--- add_markers                           # add_markers package  
    |    |--- src
    |    |    |--- markers_robot.cpp       # gets robot's odometry and marks object at pickup zone and dropoff zone for specific tasks 
    |    |    |--- add_markers.cpp         # marker test code
    |    |--- CMakeLists.txt                  
    |    |--- package.xml   
    |
    |--- map                                   
    |    |--- myworld.world                  # my gazebo world 
    |    |--- my_map.pgm                     # my gazebo map in pgm file
    |    |--- my_map.yaml                    # my gazebo map in yaml file
    |
    |--- pick_objects                          # pick_objects packages
    |    |--- src
    |    |    |--- pick_objects.cpp        # deliver object from pickup zone to dropoff zone
    |    |--- CMakeLists.txt                 
    |    |---  package.xml                   
    |
    |--- scripts                               # shell script files   
    |    |--- add_marker.sh           # launches marking task on rviz map
    |    |--- home_service.sh         # launches home service task (deliver object and visualize it using marker)
    |    |--- pick_objects.sh         # launches object pickup task without visualization of marker
    |    |--- test_navigation.sh      # test robot's navigation task using rviz
    |    |--- test_slam.sh            # test robot's slam task using slam_gmapping packages
    |
    |--- slam_gmapping                         # SLAM package             
    |
    |--- turtlebot                            # turtlebot package with turtlebot description and teleoperation
    |
    |--- turtlebot_interactions               # turtlebot rviz launchers
    |
    |--- turtlebot_simulator                  # turtlebot gazebo launcher with amcl localization
```


### Project Description
Before run `.sh`,
```
cd catkin_ws
source devel/setup.sh
cd src/Udacity_RoboNano_Project5/scripts
```
-  `./test_slam.sh`
   - This script launches slam node to test manually
	![test_slam image](images/test_slam.PNG)
-  `./test_navigation.sh`
   - This script launches navigation node to check if robot can move to goal point
	![test_navigation image](images/test_navigation.PNG)
-  `./home_service_robot.sh`
   - This script shows four actions
      - Robot moves to the pickup zone
      - Robot pick up the virtual object
      - Robot moves to the dropoff zone
      - Robot drop off the virtual object
 
	![home_service_robot image](images/home_service_robot_1.PNG)
	![home_service_robot image](images/home_service_robot_2.PNG)
	![home_service_robot image](images/home_service_robot_3.PNG)

