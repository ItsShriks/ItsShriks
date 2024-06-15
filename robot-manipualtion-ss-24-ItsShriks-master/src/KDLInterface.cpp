/*
Name: KDLInterface.cpp
Author(s):
Date:
Assignment:
Copyright:
*/
#include "youbot_kdl/KDLInterface.h"

KDLInterface::KDLInterface(){
	double offset[5] = {d2r(-169),d2r(-65),d2r(151),d2r(-102.5),d2r(-165)};

	//Use your DH parameters here!
	/** 
	 * See example in:
	 * https://github.com/orocos/orocos_kinematics_dynamics/blob/master/orocos_kdl/tests/solvertest.cpp 
	 * code lines: 105-121. 
	*/

	nr_joints = chain.getNrOfJoints();

}

KDLInterface::~KDLInterface(){

}

double KDLInterface::d2r(double v) {
	return v / 180 * M_PI;
}


bool KDLInterface::fksolver(double joint_positions[], KDL::Frame &pos){
	// From base to tooltip
	/**
	 * See example in:
	 * http://www.orocos.org/kdl/examples
	*/
}

bool KDLInterface::fksolver(double joint_positions[], KDL::Frame &pos, int link){
	//From base to some link
}
