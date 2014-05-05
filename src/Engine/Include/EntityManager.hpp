/*
 * EntityManager.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_MANAGER_HPP_
#define ENTITY_MANAGER_HPP_

#include "Manager.hpp"
#include <string>
#include <list>
#include <unordered_map>
#include <vector>

namespace Panther
{
	class Entity;

	class EntityManager : public Panther::Manager
	{
	public:
		EntityManager();
		~EntityManager();

		void process(){};

		Entity* createEntity();
		void destroyEntity(Entity* entity);
		Entity* getEntity(Panther::uint id);
		Entity* getEntityByName(std::string entityName);
		void setEntityName(Entity* entity, std::string entityName);
		int getEntityCount();

		std::vector<Entity*>* getAllEntities();

	protected:
		std::vector<Entity*>* entities;
		std::list<Entity*>* entityPool;
		std::unordered_map<std::string, Entity*>* nameMap;

		int entityCount;
		Panther::uint nextEntityId;

		void setEntity(Panther::uint id, Entity* entity);
		Panther::uint getIndex(uint id);

	};
	
}


#endif