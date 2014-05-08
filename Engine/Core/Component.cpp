/*
 * Component.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "Component.hpp"
using namespace Panther;

Component::Component(){
	__entity = NULL;
}

Component::~Component(){
	
}

Panther::Entity* Component::getEntity(){
	return __entity;
}

void Component::setEntity(Entity* entity){
	entity = entity;
}