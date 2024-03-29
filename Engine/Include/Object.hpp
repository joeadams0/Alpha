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
#include <iostream>

namespace Panther {
	class Object
	{
	public:
		Object();
		~Object();
		
		virtual std::string JSONSerialize();
		static Object* JSONDeserialize(std::string json, Object* obj);

		std::type_index getTypeIndex();
		
	private:
		
	};
}

#endif