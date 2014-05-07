/*
 * Object.hpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef OBJECT_HPP_
#define OBJECT_HPP_

#include "Common.hpp"
#include <string>
#include <typeindex>
#include <typeinfo>

namespace Panther {
	class Object
	{
	public:
		Object();
		~Object();
		
		std::string JSONSerialize();
		static Object* JSONDeserialize(std::string json, Object* obj);

		template <class T> static std::type_index getTypeIndex(T* obj){
			return std::type_index(typeid(*obj));
		}	
	private:
		
	};
}

#endif