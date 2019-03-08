#include <ros/ros.h>
#include <visualization_msgs/Marker.h>

int main( int argc, char** argv )
{
  ros::init(argc, argv, "add_markers");
  ros::NodeHandle n;
  ros::Rate r(1);
  ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 4);
  // Set our initial shape type to be a cube
  uint32_t shape = visualization_msgs::Marker::CUBE;


    ros::spinOnce();
    visualization_msgs::Marker marker;
    visualization_msgs::Marker marker2;
    visualization_msgs::Marker marker3;
    visualization_msgs::Marker marker4;
    // Set the frame ID and timestamp.  See the TF tutorials for information on these.
    marker.header.frame_id = "map";
    marker.header.stamp = ros::Time::now();

    marker2.header.frame_id = "map";
    marker2.header.stamp = ros::Time::now();

    marker3.header.frame_id = "map";
    marker3.header.stamp = ros::Time::now();

    marker4.header.frame_id = "map";
    marker4.header.stamp = ros::Time::now();

    // Set the namespace and id for this marker.  This serves to create a unique ID
    // Any marker sent with the same namespace and id will overwrite the old one
    marker.ns = "add_markers";
    marker.id = 0;

    marker2.ns = "add_markers2";
    marker2.id = 2;

    marker3.ns = "add_markers3";
    marker3.id = 3;

    marker4.ns = "add_markers4";
    marker4.id = 4;
    // Set the marker type.  Initially this is CUBE, and cycles between that and SPHERE, ARROW, and CYLINDER
    marker.type = shape;
    marker2.type = shape;
    marker3.type = shape;
    marker4.type = shape;
    // Set the marker action.  Options are ADD, DELETE, or DELETEALL.
    marker.action = visualization_msgs::Marker::ADD;
    marker2.action = visualization_msgs::Marker::ADD;
    marker3.action = visualization_msgs::Marker::ADD;
    marker4.action = visualization_msgs::Marker::ADD;
    // Set the pose of the marker.  This is a full 6DOF pose relative to the frame/time specified in the header
    marker.pose.position.x = 0.214;
    marker.pose.position.y = 9.5353;
    marker.pose.position.z = 0;
    marker.pose.orientation.x = 0.0;
    marker.pose.orientation.y = 0.0;
    marker.pose.orientation.z = 0.0;
    marker.pose.orientation.w = 0.0947;


    marker2.pose.position.x = -5.5123;
    marker2.pose.position.y = 6.0847;
    marker2.pose.position.z = 0;
    marker2.pose.orientation.x = 0.0;
    marker2.pose.orientation.y = 0.0;
    marker2.pose.orientation.z = 0.0;
    marker2.pose.orientation.w = 0.788;

    marker3.pose.position.x = 6.5995;
    marker3.pose.position.y = 3.2613;
    marker3.pose.position.z = 0;
    marker3.pose.orientation.x = 0.0;
    marker3.pose.orientation.y = 0.0;
    marker3.pose.orientation.z = 0.0;
    marker3.pose.orientation.w = 0.7576;

    marker4.pose.position.x = -2.6729;
    marker4.pose.position.y = -7.1982;
    marker4.pose.position.z = 0;
    marker4.pose.orientation.x = 0.0;
    marker4.pose.orientation.y = 0.0;
    marker4.pose.orientation.z = 0.0;
    marker4.pose.orientation.w = 0.8916;
    // Set the scale of the marker -- 1x1x1 here means 1m on a side
    marker.scale.x = 0.3;
    marker.scale.y = 0.3;
    marker.scale.z = 0.3;


    marker2.scale.x = 0.3;
    marker2.scale.y = 0.3;
    marker2.scale.z = 0.3;

    marker3.scale.x = 0.3;
    marker3.scale.y = 0.3;
    marker3.scale.z = 0.3;


    marker4.scale.x = 0.3;
    marker4.scale.y = 0.3;
    marker4.scale.z = 0.3;
    // Set the color -- be sure to set alpha to something non-zero!
    marker.color.r = 0.0f;
    marker.color.g = 1.0f;
    marker.color.b = 0.0f;
    marker.color.a = 1.0f;


    marker2.color.r = 0.0f;
    marker2.color.g = 0.0f;
    marker2.color.b = 1.0f;
    marker2.color.a = 1.0f;

    marker3.color.r = 0.0f;
    marker3.color.g = 1.0f;
    marker3.color.b = 1.0f;
    marker3.color.a = 1.0f;


    marker4.color.r = 1.0f;
    marker4.color.g = 0.0f;
    marker4.color.b = 1.0f;
    marker4.color.a = 1.0f;

    marker.lifetime = ros::Duration();

    marker2.lifetime = ros::Duration();

    marker3.lifetime = ros::Duration();

    marker4.lifetime = ros::Duration();

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
    marker_pub.publish(marker);
    marker_pub.publish(marker2);
    marker_pub.publish(marker3);
    marker_pub.publish(marker4);
    ROS_INFO("Publish markers at PickUps locations");
    // Check robot location from Paramater Server
    std::string Robot_pos;
    while (ros::ok())
    {
      if (ros::param::get("/Robot_pos", Robot_pos)){

        if (Robot_pos == "PickUp1"){
          // Hide the marker
          marker.action = visualization_msgs::Marker::DELETE;
          // Publish marker
          marker_pub.publish(marker);
          ROS_INFO("Remove marker from PickUp location");

          // Sleep 5 sec
          ros::Duration(5.0).sleep();
        }
        if (Robot_pos == "PickUp2"){
          
          // Show the marker at dropoff location
          marker2.action = visualization_msgs::Marker::DELETE;
          // Publish marker
          marker_pub.publish(marker2);
          ROS_INFO("Remove marker to PickUp2 location");

          // Sleep 5 sec
          ros::Duration(5.0).sleep();
        }
        if (Robot_pos == "PickUp3"){
          
          // Show the marker at dropoff location
          marker3.action = visualization_msgs::Marker::DELETE;
          // Publish marker
          marker_pub.publish(marker3);
          ROS_INFO("Remove marker to PickUp3 location");

          // Sleep 5 sec
          ros::Duration(5.0).sleep();
        }
        if (Robot_pos == "PickUp4"){
          
          // Show the marker at dropoff location
          marker4.action = visualization_msgs::Marker::DELETE;
          // Publish marker
          marker_pub.publish(marker4);
          ROS_INFO("Remove marker to PickUp2 location");

          // Sleep 5 sec
          ros::Duration(5.0).sleep();
        }
        if (Robot_pos == "DropOff"){
          // Set the DropOff location of the marker
          marker.color.r = 1.0f;
          marker.color.g = 0.0f;
          marker.color.b = 0.0f;
          marker.color.a = 1.0f;
          marker.pose.position.x = 0;
          marker.pose.position.y = 0;
          marker.pose.position.z = 0;
          marker.pose.orientation.x = 0.0;
          marker.pose.orientation.y = 0.0;
          marker.pose.orientation.z = 0.0;
          marker.pose.orientation.w = 0.788;
          // Show the marker at dropoff location
          marker.action = visualization_msgs::Marker::ADD;
          // Publish marker
          marker_pub.publish(marker);
          ROS_INFO("Publish marker to DropOff location"); 
        }
      }
    

    r.sleep();
    }
}