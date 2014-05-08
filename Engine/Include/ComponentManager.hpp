/*
 * ComponentManager.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef COMPONENT_MANAGER_HPP_
#define COMPONENT_MANAGER_HPP_

#include "Manager.hpp"
#include "Message.hpp"
#include "Scene.hpp"
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include <vector>
#include <list>
#include <boost/dynamic_bitset.hpp>
#include <iostream>

namespace Panther {
	class Component;
	class EntityComposition;

	class ComponentManager : public Panther::Manager
	{
	public:
		ComponentManager();
		~ComponentManager();
		
		void process(){};

		void addComponent(Panther::Entity* entity, Panther::Component* component);
		void addComponents(Panther::Entity* entity, std::vector<Component*>* comps);
		template<class T> T* removeComponent(Panther::Entity* entity){
			Panther::uint bit = getComponentBitByClass(std::type_index(typeid(T)));
			
			T* obj = dynamic_cast<T*>((*((*componentMaps)[bit]))[entity]);
			(*componentMaps)[bit]->erase(entity);

			setComponentBit(entity, bit, false);
			
			Message* message = new Message(Message::ENTITY_COMPOSITION_CHANGED);
			message->setProperty<Entity*>("entity", entity);
			getScene()->sendMessage(message);

			obj->setEntity(NULL);
			
			return obj;
		};
		void removeAllComponents(Panther::Entity* entity);

		void setComponentBit(Panther::Entity* entity, Panther::uint bit, bool val);
		// Get a component from an entity
		template<class T> T* getComponent(Panther::Entity* entity);
		// Get all components for given entity
		std::list<Panther::Component*>* getComponents(Entity* entity);
		// Get all components of a single type
		template<class T> std::list<T*>* getComponents();
		// Gets all entities that fit a composition
		std::list<Panther::Entity*>* getEntities(Panther::EntityComposition* composition);		
		template<class T> bool hasComponent(Panther::Entity* entity);

		// Gets the bit that represents the component class for the component, -1 if it does not exist
		static Panther::uint getComponentBitByClass(Panther::Component* component);
		template<class T> static Panther::uint getComponentBitByClass(){
			return getComponentBitByClass(std::type_index(typeid(T)));
		}
		static bool hasComponent(Panther::Entity* entity, Panther::uint bit);

	protected:
		std::vector<std::unordered_map<Panther::Entity*, Panther::Component*>*>* componentMaps; 
		boost::dynamic_bitset<>* flags;
		// Maps component type to bit index
		static std::unordered_map<std::type_index, Panther::uint>* compTypeToBitMap;

		static Panther::uint nextBit;

		static Panther::uint getComponentBitByClass(std::type_index type);
		static Panther::uint createComponentClassBit(std::type_index type);

		std::unordered_map<Panther::Entity*, Panther::Component*>* getComponentMap(Panther::uint index);
		
		void addComponent(Panther::Entity* entity, Panther::Component* component, bool sendMessage);		
	};
}

#endif