/*
 * EntityDestroyedEvent.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "../Include/EntityDestroyedEvent.hpp"

using namespace Panther;

EntityDestroyedEvent::EntityDestroyedEvent(Entity* entity){
	destroyedEntity = entity;
}

EntityDestroyedEvent::~EntityDestroyedEvent(){

}

Entity* EntityDestroyedEvent::getDestroyedEntity(){
	return destroyedEntity;
}