## Udacity RoboNano Project5 : Home Service Robot

### Project
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

