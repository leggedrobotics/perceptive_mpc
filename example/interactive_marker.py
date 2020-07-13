#! /usr/bin/env  python

import copy
import rospy

from geometry_msgs.msg import Quaternion, PoseStamped, Pose, Point
from interactive_markers.interactive_marker_server import *
from interactive_markers.menu_handler import *
from visualization_msgs.msg import *


class SingleMarkerBroadcaster:
    def __init__(self):
        self.server = InteractiveMarkerServer("target_pose")
        self.pose = PoseStamped()

        self.pose_pub = rospy.Publisher('/perceptive_mpc/desired_end_effector_pose', PoseStamped, queue_size=1)

        self.global_frame = 'odom'

    def makeBox(self, msg):
        marker = Marker()

        marker.type = Marker.SPHERE
        marker.scale.x = msg.scale * 0.45
        marker.scale.y = msg.scale * 0.45
        marker.scale.z = msg.scale * 0.45
        marker.color.r = 0.0
        marker.color.g = 0.5
        marker.color.b = 0.5
        marker.color.a = 0.5
        return marker

    def create_marker(self):
        self.int_marker = InteractiveMarker()
        int_marker = self.int_marker
        int_marker.header.frame_id = self.global_frame
        int_marker.header.stamp = rospy.Time.now()
        self.pose.header = int_marker.header

        int_marker.pose.position.x = 1.0
        int_marker.pose.position.y = 0.0
        int_marker.pose.position.z = 0.0
        self.pose.pose.position = int_marker.pose.position

        int_marker.pose.orientation.x = -0.707
        int_marker.pose.orientation.y = 0.707
        int_marker.pose.orientation.z = 0.0
        int_marker.pose.orientation.w = 0.0
        self.pose.pose.orientation = int_marker.pose.orientation


        int_marker.scale = 0.2

        int_marker.name = "PoseTarget"
        int_marker.description = "Pose target for the end effector"

        control = InteractiveMarkerControl()

        # Custom move on plane
        control.orientation.w = 1
        control.orientation.x = 1
        control.orientation.y = 0
        control.orientation.z = 0
        control.name = "rotate_x"
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(copy.deepcopy(control))
        control.name = "move_x"
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(copy.deepcopy(control))

        control.orientation.w = 1
        control.orientation.x = 0
        control.orientation.y = 1
        control.orientation.z = 0
        control.name = "rotate_z"
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(copy.deepcopy(control))
        control.name = "move_z"
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(copy.deepcopy(control))

        control.orientation.w = 1
        control.orientation.x = 0
        control.orientation.y = 0
        control.orientation.z = 1
        control.name = "rotate_y"
        control.interaction_mode = InteractiveMarkerControl.ROTATE_AXIS
        int_marker.controls.append(copy.deepcopy(control))
        control.name = "move_y"
        control.interaction_mode = InteractiveMarkerControl.MOVE_AXIS
        int_marker.controls.append(copy.deepcopy(control))
        control.interaction_mode = InteractiveMarkerControl.MOVE_ROTATE_3D


        control.interaction_mode = InteractiveMarkerControl.BUTTON
        control.name = "click"
        control.markers.append(self.makeBox(int_marker))
        int_marker.controls.append(copy.deepcopy(control))

        self.server.insert(int_marker, self.update_pose_callback)

    def apply_changes(self):
        self.server.applyChanges()

    def update_pose_callback(self, feedback):
        if feedback.event_type == InteractiveMarkerFeedback.POSE_UPDATE:
            self.pose.header.frame_id = self.global_frame
            self.pose.header.stamp = rospy.Time.now()
            self.pose.pose.position = feedback.pose.position
            self.pose.pose.orientation = feedback.pose.orientation
        elif feedback.event_type == InteractiveMarkerFeedback.BUTTON_CLICK:
            rospy.loginfo("Marker clicked, publish new goal!")
            self.pose_pub.publish(self.pose)

if __name__ == '__main__':
    rospy.init_node('target_pose_publisher', anonymous=True)

    try:
        interactiveTargetPose = SingleMarkerBroadcaster()
        interactiveTargetPose.create_marker()
        interactiveTargetPose.apply_changes()
    except rospy.ROSInterruptException:
        pass

    rospy.spin()
