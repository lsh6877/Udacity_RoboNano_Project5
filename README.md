## Udacity RoboNano Project5 : Home Service Robot

### Directory and packages description

```
    Udacity_RoboNano_Project5                          # Home Service Robot Project
    ~T~\~T~@~T~@ add_markers                           # add_markers package  
    ~T~B   ~T~\~T~@~T~@ src
    ~T~B   ~T~B   ~T~\~T~@~T~@ markers_robot.cpp       # gets robot's odometry and marks object at pickup zone and dropoff zone for specific tasks    
    ~T~B   ~T~B   ~T~\~T~@~T~@ add_markers.cpp         # marker test code
    ~T~B   ~T~\~T~@~T~@ CMakeLists.txt                  
    ~T~B   ~T~\~T~@~T~@ package.xml                    

    ~T~\~T~@~T~@ map                                   
    ~T~B   ~T~\~T~@~T~@ myworld.world                  # my gazebo world 
    ~T~B   ~T~\~T~@~T~@ my_map.pgm                     # my gazebo map in pgm file
    ~T~B   ~T~\~T~@~T~@ my_map.yaml                    # my gazebo map in yaml file

    ~T~\~T~@~T~@ pick_objects                          # pick_objects packages
    ~T~B   ~T~\~T~@~T~@ src
    ~T~B   ~T~B   ~T~\~T~@~T~@ pick_objects.cpp        # deliver object from pickup zone to dropoff zone
    ~T~B   ~T~\~T~@~T~@ CMakeLists.txt                 
    ~T~B   ~T~\~T~@~T~@ package.xml                   

    ~T~\~T~@~T~@ scripts                               # shell script files   
    ~T~B   ~T~B   ~T~\~T~@~T~@ add_marker.sh           # launches marking task on rviz map
    ~T~B   ~T~B   ~T~\~T~@~T~@ home_service.sh         # launches home service task (deliver object and visualize it using marker)
    ~T~B   ~T~B   ~T~\~T~@~T~@ pick_objects.sh         # launches object pickup task without visualization of marker
    ~T~B   ~T~B   ~T~\~T~@~T~@ test_navigation.sh      # test robot's navigation task using rviz
    ~T~B   ~T~B   ~T~\~T~@~T~@ test_slam.sh            # test robot's slam task using slam_gmapping packages

    ~T~\~T~@~T~@ slam_gmapping                         # SLAM package             
 
    ~T~\~T~@~T~@ turtlebot                            # turtlebot package with turtlebot description and teleoperation
    ~T~\~T~@~T~@ turtlebot_interactions               # turtlebot rviz launchers
    ~T~T~T~@~T~@ turtlebot_simulator                  # turtlebot gazebo launcher with amcl localization
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

