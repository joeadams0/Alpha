/*
 * Manager.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef MANAGER_HPP_
#define MANAGER_HPP_

#include "SceneObject.hpp"

namespace Panther {
	class Manager : public Panther::SceneObject
	{
	public:
		Manager();
		~Manager();

		void awake();
		void sleep();
		bool isActive();
		virtual void process() = 0;
		
	protected:
		bool active;
	};
}


#endif