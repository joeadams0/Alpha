/*
 * EntityManager.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "EntityManager.hpp"
#include "Entity.hpp"
#include "Message.hpp"
#include <iostream>

using namespace Panther;

EntityManager::EntityManager(){
	entities = new std::vector<Entity*>();
	entityPool = new std::list<Entity*>();
	nameMap = new std::unordered_map<std::string, Entity*>();
	entityCount = 0;
	nextEntityId = 1;
}

EntityManager::~EntityManager(){
	delete entities;
	delete entityPool;
	delete nameMap;
}

Entity* EntityManager::createEntity(){
	return createEntity(true);
}

Entity* EntityManager::createEntity(bool sendMessage){
	Entity* entity;
	if(entityPool->empty()){
		entity = new Entity(nextEntityId);
		nextEntityId++;
	}
	else{
		entity = entityPool->back();
		entityPool->pop_back();
	}

	entity->setScene(getScene());

	setEntity(entity->getEntityId(), entity);
	if(sendMessage){
		Message* message = new Message(Message::ENTITY_CREATED);
		message->setProperty<Entity*>("entity", entity);
		getScene()->sendMessage(message);
	}
	
	return entity;
}

void EntityManager::destroyEntity(Entity* entity){
	destroyEntity(entity, true);
}

void EntityManager::destroyEntity(Entity* entity, bool sendMessage){
	entityPool->push_front(entity);
	
	if(sendMessage){
		Message* message = new Message(Message::ENTITY_DESTROYED);
		message->setProperty<Entity*>("entity", entity);
		getScene()->sendMessage(message);
	}

	setEntity(entity->getEntityId(), NULL);
}

Entity* EntityManager::getEntityById(uint id){
	return (*entities)[getIndex(id)];
}

Entity* EntityManager::getEntityByName(std::string entityName){
	return (*nameMap)[entityName];
}

std::vector<Entity*>* EntityManager::getAllEntities(){
	return entities;
}

// Ids are shifted back one for index. So index = id-1
void EntityManager::setEntity(uint id, Entity* entity){	
	entities->insert(entities->begin()+getIndex(id), entity);
}

void EntityManager::setEntityName(Entity* entity, std::string entityName){
	(*entities)[getIndex(entity->getEntityId())] = entity;
}

uint EntityManager::getIndex(uint id){
	return id-1;
}

int EntityManager::getEntityCount(){
	return entityCount;
}
