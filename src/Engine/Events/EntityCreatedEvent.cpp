/*
 * EntityCreatedEvent.cpp
 *
 *  Created on: May 35, 2014
 *      Author: Joe Adams
 */

#include "../Include/EntityCreatedEvent.hpp"

using namespace Panther;

EntityCreatedEvent::EntityCreatedEvent(Entity* entity){
	createdEntity = entity;
}

EntityCreatedEvent::~EntityCreatedEvent(){

}

Entity* EntityCreatedEvent::getCreatedEntity(){
	return createdEntity;
}