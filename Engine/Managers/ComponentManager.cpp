/*
 * ComponentManager.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "ComponentManager.hpp"
#include "Component.hpp"
#include "Entity.hpp"
#include "EntityComposition.hpp"
#include "EntityManager.hpp"
#include "Message.hpp"
#include <iostream>

using namespace Panther;

std::unordered_map<std::type_index, uint>* ComponentManager::compTypeToBitMap = new std::unordered_map<std::type_index, uint>();
uint ComponentManager::nextBit = 0;

ComponentManager::ComponentManager(){
	componentMaps = new std::vector<std::unordered_map<Entity*, Component*>*>();
	flags = new boost::dynamic_bitset<>(5);
}

ComponentManager::~ComponentManager(){
	delete componentMaps;
	delete flags;
}

void ComponentManager::addComponent(Entity* entity, Component* component){
	addComponent(entity, component, true);
}

void ComponentManager::addComponent(Entity* entity, Component* component, bool sendMessage){
	component->setScene(getScene());
	component->setEntity(entity);

	uint bit = getComponentBitByClass(component);	
	getComponentMap(bit)->insert(std::make_pair<Entity*,Component*>(entity,component));

	setComponentBit(entity, bit, true);

	if(sendMessage){
		Message* message = new Message(Message::ENTITY_COMPOSITION_CHANGED);
		message->setProperty<Entity*>("entity", entity);
		getScene()->sendMessage(message);
	}
}

void ComponentManager::addComponents(Entity* entity, std::vector<Component*>* comps){
	std::vector<Component*>::iterator it = comps->begin();
	for(; it != comps->end(); ++it){
		addComponent(entity, (*it), false);
	}
	Message* message = new Message(Message::ENTITY_COMPOSITION_CHANGED);
	message->setProperty<Entity*>("entity", entity);
	getScene()->sendMessage(message);
}

void ComponentManager::removeAllComponents(Entity* entity){
	std::vector<std::unordered_map<Entity*, Component*>*>::iterator it = componentMaps->begin();
	while(it != componentMaps->end()){
		(*it)->erase(entity);
		setComponentBit(entity, it-componentMaps->begin(),false);
		++it;
	}
	Message* message = new Message(Message::ENTITY_COMPOSITION_CHANGED);
	message->setProperty<Entity*>("entity", entity);
	getScene()->sendMessage(message);
}

std::list<Component*>* ComponentManager::getComponents(Entity* entity){
	std::list<Component*>* components = new std::list<Component*>();

	std::vector<std::unordered_map<Entity*, Component*>*>::iterator it = componentMaps->begin();
	int bitIndex = 0;
	while(it != componentMaps->end()){
		if(hasComponent(entity, bitIndex)){
			components->push_front((*(*it))[entity]);
		}

		bitIndex++;
		++it;
	}	

	return components;
}

void ComponentManager::setComponentBit(Entity* entity, uint bit, bool val){
	(*(entity->getComposition()))[bit] = val;
}

std::list<Entity*>* ComponentManager::getEntities(EntityComposition* composition){
	std::list<Entity*>* entities = new std::list<Entity*>();
	std::vector<Entity*>* allEntities = getScene()->getEntityManager()->getAllEntities();

	for (std::vector<Entity*>::iterator it = allEntities->begin() ; it != allEntities->end(); ++it){
		if((*it)->matchesComposition(composition)){
			entities->push_front(*it);
		}
	}

	return entities;
}

uint ComponentManager::getComponentBitByClass(Component* component){
	return getComponentBitByClass(component->getTypeIndex());
}

uint ComponentManager::getComponentBitByClass(std::type_index type){
	std::unordered_map<std::type_index, uint>::const_iterator got = compTypeToBitMap->find(type);

	if(got == compTypeToBitMap->end()){
		return createComponentClassBit(type);
	}
	else
		return got->second;
}

uint ComponentManager::createComponentClassBit(std::type_index type){	
	(*compTypeToBitMap)[type] = nextBit;

	uint bit = nextBit;
	nextBit++;

	return bit;
}

bool ComponentManager::hasComponent(Entity* entity, uint bit){
	return false;
}

std::unordered_map<Entity*, Component*>* ComponentManager::getComponentMap(uint index){
	if(!(*flags)[index]){
		(*componentMaps)[index] = new std::unordered_map<Entity*, Component*>(); 
		(*flags)[index] = true;
	}

	return (*componentMaps)[index];
}