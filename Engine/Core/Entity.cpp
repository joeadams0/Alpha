/*
 * Entity.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "Entity.hpp"
#include "EntityComposition.hpp"
#include "EntityManager.hpp"

using namespace Panther;

Entity::Entity(Panther::uint id){
	entityId = id;
	composition = new boost::dynamic_bitset<>(16);
}

Entity::~Entity(){
	delete composition;
}

uint Entity::getEntityId(){
	return entityId;
}

void Entity::addComponent(Component* component){
	getScene()->getComponentManager()->addComponent(this, component);
}

void Entity::removeAllComponents(){
	getScene()->getComponentManager()->removeAllComponents(this);
}

std::list<Component*>* Entity::getComponents(){
	return getScene()->getComponentManager()->getComponents(this);
}

boost::dynamic_bitset<>* Entity::getComposition() {
	return composition;
}

bool Entity::matchesComposition(EntityComposition* composition){
	return composition->matches(this->getComposition());
}

void Entity::destroy(){
	getScene()->getEntityManager()->destroyEntity(this);
}