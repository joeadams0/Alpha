/*
 * EntityComposition.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITYCOMPOSITION_HPP_
#define ENTITYCOMPOSITION_HPP_

#include "SceneObject.hpp"
#include "ComponentManager.hpp"
#include <vector>

namespace Panther {

	class Entity;

	class EntityComposition : public Panther::SceneObject
	{
	public:
		EntityComposition();
		~EntityComposition();

		std::vector<bool>* getAllSet();
		std::vector<bool>* getSomeSet();
		std::vector<bool>* getNoneSet();

		bool matches(std::vector<bool>* composition);

		template<class T>
		void all(){
			(*allSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = true;
		}

		template<class T>
		void some(){
			(*someSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = true;
		}

		template<class T>
		void none(){
			(*someSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = true;
		}

	protected:
		std::vector<bool>* allSet;
		std::vector<bool>* someSet;
		std::vector<bool>* noneSet; 


		bool matchesAllSet(std::vector<bool>* set);
		bool matchesSomeSet(std::vector<bool>* set);
		bool matchesNoneSet(std::vector<bool>* set);

	};
}

#endif