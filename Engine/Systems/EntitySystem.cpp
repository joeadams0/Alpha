/*
 * EntitySystem.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "EntitySystem.hpp"
#include <iostream>
#include <algorithm>
#include "Message.hpp"
#include "Entity.hpp"

using namespace Panther;

EntitySystem::EntitySystem(){

}

EntitySystem::~EntitySystem(){

}

void EntitySystem::awake(){
	getScene()->addMessageListener(Message::ENTITY_CREATED, this);
	getScene()->addMessageListener(Message::ENTITY_DESTROYED, this);
	getScene()->addMessageListener(Message::ENTITY_COMPOSITION_CHANGED, this);
}

void EntitySystem::process(){
	for (std::set<Entity*>::iterator it=entities.begin(); it!=entities.end(); ++it)
    	processEntity(*it);
}

void EntitySystem::processEntity(Entity* entity){

}

std::set<Entity*> EntitySystem::getEntities(){
	return entities;
}

void EntitySystem::handleMessage(Message* message){
	int messageType = message->getMessageType();
	Entity* ent = message->getProperty<Entity*>("entity");

	if(messageType == Message::getMessageType(Message::ENTITY_CREATED)){
		if(interestedInEntity(ent)){
			addEntity(ent);
		}
	}
	else if(messageType == Message::getMessageType(Message::ENTITY_DESTROYED)){
		removeEntity(ent);
	}
	else if(messageType == Message::getMessageType(Message::ENTITY_COMPOSITION_CHANGED)){
		if(interestedInEntity(ent)){
			addEntity(ent);
		}
		else{
			removeEntity(ent);
		}

	}
}

void EntitySystem::addEntity(Entity* entity){
	entities.insert(entity);
}

void EntitySystem::removeEntity(Entity* entity){
	entities.erase(entity);
}

bool EntitySystem::interestedInEntity(Entity* entity){
	return entity->matchesComposition(composition);
}

void EntitySystem::setEntityComposition(EntityComposition* comp){
	composition = comp;
}