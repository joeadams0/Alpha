/*
 * Component.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "../Include/Component.hpp"

using namespace Panther;

Component::Component(){
	__entity = NULL;
}

Component::~Component(){
	
}

Panther::Entity* Component::getEntity(){
	return __entity;
}