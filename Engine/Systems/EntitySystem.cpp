/*
 * EntitySystem.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "EntitySystem.hpp"
#include <iostream>
#include "Message.hpp"
#include "Entity.hpp"

using namespace Panther;

EntitySystem::EntitySystem(){

}

EntitySystem::~EntitySystem(){

}

void EntitySystem::awake(){
	getScene()->addMessageListener("engine_entity_created", this);
}

void EntitySystem::handleMessage(Message* message){
	
}