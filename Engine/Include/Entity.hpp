/*
 * Entity.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_HPP
#define ENTITY_HPP

#include "SceneObject.hpp"
#include "../Include/Scene.hpp"
#include "../Include/ComponentManager.hpp"
#include <list>
#include <boost/dynamic_bitset.hpp>

namespace Panther {
	class Component;
	class EntityComposition;

	class Entity : public Panther::SceneObject
	{
	public:
		Entity(Panther::uint id);
		~Entity();
		
		Panther::uint getEntityId();
		void addComponent(Panther::Component* component);
		void removeAllComponents();
		std::list<Panther::Component*>* getComponents();
		boost::dynamic_bitset<>* getComposition();

		bool matchesComposition(Panther::EntityComposition* composition);

		void destroy();


		template<class T> T* removeComponent(){
			return getScene()->getComponentManager()->removeComponent<T>(this);
		}
		template<class T> T* getComponent(){
			return getScene()->getComponentManager()->getComponent<T>(this);
		}
		template<class T> bool hasComponent(){
			return getScene()->getComponentManager()->hasComponent<T>(this);
		}


	protected:
		Panther::uint entityId;
		boost::dynamic_bitset<>* composition;


	};
}

#endif