#ifndef TELEOP_CMD_H_
#define TELEOP_CMD_H_

#pragma once

#include <ros/ros.h>
#include <std_msgs/String.h>
#include <std_msgs/Float64.h>
#include <sensor_msgs/JointState.h>

#include <iostream>
#include <sstream>
#include <string>

class Franka_robot{

private:
	std::vector<std::string> joint_names;
	std::vector<double> joint_goal_positions;
	std::vector<double> joint_velocities;
	std::vector<double> joint_efforts;

	int const FRANKA_ROBOT_JOINT_NUMBER = 7;
public:
	void setJointNames(){
		//Sets default names
		for (int i = 0; i < FRANKA_ROBOT_JOINT_NUMBER; ++i)
		{
			std::stringstream ss;
			ss << i+1;
			std::string str = "panda_joint"+ss.str();
			joint_names.push_back(str);
			//std::cout << str << std::endl;
		}
	}
	void setJointName(int joint_id,std::string jointName){
		joint_names[joint_id] = jointName;
	}	
	std::vector<std::string> getJointNames() const{
		return joint_names;
	}

	void setJointStartPosition(){
		//Set joint goal positions to starting position
		joint_goal_positions = {0+(M_PI_4/2), -M_PI_4, 0, -3 * M_PI_4, 0, M_PI_2, M_PI_4};
	}
	void setJointGoalPosition(int joint_id, float joint_goal_position){
		joint_goal_positions[joint_id] = joint_goal_position;
	} 	
	std::vector<double> getJointGoalPosition(){
		return joint_goal_positions;
	}

	void setJointVelocities(){
		joint_velocities = {1,0,0,0,0,0,0};
	}
	void setJointVelocity(int joint_id, float joint_velocity){
		joint_velocities[joint_id] = joint_velocity;
	}
	std::vector<double> getJointVelocities(){
		return joint_velocities;
	}

	void setJointEffort(){
		joint_efforts = {1,1,1,1,1,1,1};
	}
	void setJointEffort(int joint_id, float joint_effort){
		joint_efforts[joint_id] = joint_effort;
	}


};

#endif