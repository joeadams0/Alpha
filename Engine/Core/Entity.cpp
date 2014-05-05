/*
 * Entity.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "../Include/Entity.hpp"
#include "../Include/EntityComposition.hpp"

using namespace Panther;

Entity::Entity(Panther::uint id){
	entityId = id;
	composition = new std::vector<bool>();
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

std::vector<bool>* Entity::getComposition() {
	return composition;
}

bool Entity::matchesComposition(EntityComposition* composition){
	return composition->matches(this->getComposition());
}