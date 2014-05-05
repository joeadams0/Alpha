/*
 * Scene.hpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef SCENE_HPP_
#define SCENE_HPP_

#include <string>
#include <list>
#include <vector>
#include <unordered_map>
#include <typeindex>
#include <typeinfo>
#include "Object.hpp"
#include "EventManager.hpp"
#include "../Include/SystemManager.hpp"

namespace Panther{
	class World;
	class Entity;
	class Component;
	class EntityComposition;
	class Manager;
	class SystemManager;
	class EntityManager;
	class ComponentManager;

	class Scene : public Panther::Object, public Panther::EventManager {
	public:
		Scene(std::string sceneName);
		~Scene();

		void init();
		void awake();
		void sleep();
		bool isAwake();
		bool isInit();

		Panther::Entity* createEntity();

		Panther::Entity* getEntityByName(std::string name);

		void addSystem(Panther::System* system);

		template<class T> T* removeSystem(){
			return getSystemManager()->removeSystem<T>();
		}


		template<class T> T* getSystem(){
			return getSystemManager()->getSystem<T>();
		}

		/**
		 * Managers
		 */
		
		void addManager(Panther::Manager* manager);
		// Get manager of specified type
		template<class T> T* getManager(){
			return dynamic_cast<T*>((*managers)[std::type_index(typeid(T))]);
		}

		template<class T> T* removeManager(){
			std::type_index type = std::type_index(typeid(T));
			T* manager = dynamic_cast<T*>((*managers)[type]);
			managers->erase(type);
			return manager;
		}		

		Panther::SystemManager* getSystemManager();

		Panther::ComponentManager* getComponentManager();

		Panther::EntityManager* getEntityManager();



		std::string getSceneName();
		Panther::World* getWorld();

		// Called by engine. Do not use
		void setWorld(Panther::World* w);

		void process();
	
	protected:
		std::string sceneName;
		Panther::World* world;
		std::unordered_map<std::type_index, Panther::Manager*>* managers;
		bool _awake;
		bool _init;
	};
}


#endif /* SCENE_HPP_ */
