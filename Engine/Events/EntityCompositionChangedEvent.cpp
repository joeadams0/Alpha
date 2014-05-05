/*
 * EntityCompositionChangedEvent.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "../Include/EntityCompositionChangedEvent.hpp"

using namespace Panther;

EntityCompositionChangedEvent::EntityCompositionChangedEvent(Entity* entity){
	changedEntity = entity;
}

EntityCompositionChangedEvent::~EntityCompositionChangedEvent(){

}

Entity* EntityCompositionChangedEvent::getChangedEntity(){
	return changedEntity;
}