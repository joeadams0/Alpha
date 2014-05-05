/*
 * SystemManager.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef SYSTEM_MANAGER_HPP_
#define SYSTEM_MANAGER_HPP_

#include "Manager.hpp"
#include <unordered_map>
#include <typeindex>
#include <typeinfo>

namespace Panther {

	class System;

	class SystemManager : public Panther::Manager
	{
	public:
		SystemManager();
		~SystemManager();
		
		void process();

		void addSystem(Panther::System* system);

		template<class T> T* removeSystem(){
			return dynamic_cast<T*>((*systems)[std::type_index(typeid(T))]);
		}

		template<class T> T* getSystem(){
			std::type_index type = std::type_index(typeid(T));
			T* system = dynamic_cast<T*>((*systems)[type]);
			systems->erase(type);
			return system;
		}

	protected:
		std::unordered_map<std::type_index, Panther::System*>* systems;
	};
}

#endif