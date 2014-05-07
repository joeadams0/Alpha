/*
 * System.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "System.hpp"

using namespace Panther;

System::System(){
	_awake = false;
}

System::~System(){
	
}


void System::process(){

}

void System::awake(){
	_awake = true;
}

void System::sleep(){
	_awake = false;
}

bool System::isAwake(){
	return _awake;
}