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

void EntitySystem::handleMessage(Message* message){
	int messageType = message->getMessageType();
	Entity* ent = message->getProperty<Entity*>("entity");

	if(messageType == Message::getMessageType(Message::ENTITY_CREATED)){
		if(interestedInEntity(ent))
			entities.push_back(ent);
	}
	else if(messageType == Message::getMessageType(Message::ENTITY_DESTROYED)){
		entities.erase(std::remove(entities.begin(), entities.end(), ent));
	}
	else if(messageType == Message::getMessageType(Message::ENTITY_COMPOSITION_CHANGED)){
		if(interestedInEntity(ent)){
			entities.push_back(ent);
		}
		else{
			entities.erase(std::remove(entities.begin(), entities.end(), ent));
		}

	}
}

bool EntitySystem::interestedInEntity(Entity* entity){
	return entity->matchesComposition(composition);
}

void EntitySystem::setEntityComposition(EntityComposition* comp){
	composition = comp;
}

int EntitySystem::getEntityCount(){
	return entities.size();
}