/*
 * Manager.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "Manager.hpp"

using namespace Panther;

Manager::Manager() {
	active = false;
}

Manager::~Manager() {

}

void Manager::awake(){
	active = true;
}

void Manager::sleep(){
	active = false;
}

bool Manager::isActive(){
	return active;
}