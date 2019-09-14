#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
#include <nav_msgs/Odometry.h>
#include <geometry_msgs/Pose2D.h>

geometry_msgs::Pose2D current_pose;

bool atposition(float goal_x, float goal_y)
{
   float del_x = goal_x - current_pose.x;
   del_x = del_x > 0 ? del_x : -del_x;

   float del_y = goal_y - current_pose.y;
   del_y = del_y > 0 ? del_y : -del_y;


   ROS_INFO("cur %f %f", current_pose.x, current_pose.y);
   ROS_INFO("goal %f %f", goal_x, goal_y);
   ROS_INFO("del %f %f", del_x, del_y);
   if(del_x < 0.5 && del_y < 0.5)
      return true;
   else
      return false;
}

void odom_sub_Callback(const nav_msgs::Odometry::ConstPtr msg)
{
   current_pose.x = msg->pose.pose.position.y;
   current_pose.y = -msg->pose.pose.position.x;
   ROS_INFO("%f %f", current_pose.x, current_pose.y);
}

int main( int argc, char** argv )
{
  ros::init(argc, argv, "markers_robot");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
  ros::Subscriber odom_sub = n.subscribe("/odom", 1, odom_sub_Callback);

  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;

  while (ros::ok())
  {
    visualization_msgs::Marker marker;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "/map";
    marker.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "cube_marker";
    marker.id = 0;

    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;

    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.5;
    marker.scale.y = 0.5;
    marker.scale.z = 0.5;

    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 0.0f;
    marker.color.b = 1.0f;
    marker.color.a = 1.0;

    marker.lifetime = ros::Duration();
    
    // Publish the marker
    while (marker_pub.getNumSubscribers() < 1)
    {
      if (!ros::ok())
      {
        return 0;
      }
      ROS_WARN_ONCE("Please create a subscriber to the marker");
      sleep(1);
    }

    ROS_INFO("Virtual Object is at pickup zone");
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = 5.15;
    marker.pose.position.y = -0.125;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker_pub.publish(marker);
    sleep(5);

    while(!atposition(5.15, -0.125))
    {
	ROS_INFO("Robot is moving to pickup zone");
        ros::spinOnce();
        sleep(1);
    }

    ROS_INFO("Robot is picking virtual object");
    marker.action = visualization_msgs::Marker::DELETE;
    marker_pub.publish(marker);
    sleep(5);

    while(!atposition(-2, 2.5))
    {
	ROS_INFO("Robot is moving to dropoff zone");
        ros::spinOnce();
	sleep(1);
    }

    ROS_INFO("Virtual Object is at dropoff zone");
    marker.action = visualization_msgs::Marker::ADD;
    marker.pose.position.x = -2;
    marker.pose.position.y = 2.5;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 1.0;
    marker_pub.publish(marker);

    r.sleep();
    break;
  }
  return 0;
}
