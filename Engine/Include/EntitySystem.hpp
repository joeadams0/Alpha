/*
 * EntitySystem.hpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_SYSTEM_HPP_
#define ENTITY_SYSTEM_HPP_

#include "System.hpp"
#include "IMessageListener.hpp"
#include <vector>
#include <set>

namespace Panther{

	class EntityComposition;
	class Entity;

	class EntitySystem : public Panther::System, Panther::IMessageListener
	{
	public:
		EntitySystem();
		~EntitySystem();
		
		virtual void awake();
		virtual void handleMessage(Panther::Message* Message);

		virtual void process();
		virtual void processEntity(Entity* entity);

		virtual std::set<Panther::Entity*> getEntities();


	protected:
		std::set<Panther::Entity*> entities;
		Panther::EntityComposition* composition;

		virtual void setEntityComposition(Panther::EntityComposition* composition);
		virtual bool interestedInEntity(Panther::Entity* entity);

		virtual void addEntity(Panther::Entity* entity);
		virtual void removeEntity(Panther::Entity* entity);

	
	};
}

#endif