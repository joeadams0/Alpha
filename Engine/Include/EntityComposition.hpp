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
#include <boost/dynamic_bitset.hpp>

namespace Panther {

	class Entity;

	class EntityComposition : public Panther::SceneObject
	{
	public:
		EntityComposition();
		~EntityComposition();

		boost::dynamic_bitset<>* getAllSet();
		boost::dynamic_bitset<>* getSomeSet();
		boost::dynamic_bitset<>* getNoneSet();

		bool matches(boost::dynamic_bitset<>* composition);

		template<class T>
		void all(){
			(*allSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = 1;
		}

		template<class T>
		void some(){
			(*someSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = 1;
		}

		template<class T>
		void none(){
			(*someSet)[Panther::ComponentManager::getComponentBitByClass<T>()] = 1;
		}

	protected:
		boost::dynamic_bitset<>* allSet;
		boost::dynamic_bitset<>* someSet;
		boost::dynamic_bitset<>* noneSet; 


		bool matchesAllSet(boost::dynamic_bitset<>* set);
		bool matchesSomeSet(boost::dynamic_bitset<>* set);
		bool matchesNoneSet(boost::dynamic_bitset<>* set);

	};
}

#endif