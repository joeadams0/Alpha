/*
 * System.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef SYSTEM_HPP_
#define SYSTEM_HPP_

#include "SceneObject.hpp"

namespace Panther {

	class System : public Panther::SceneObject
	{
	public:
		System();
		~System();
		
		virtual void process();

		virtual void awake();
		virtual void sleep();
		bool isAwake();

	protected:
		bool _awake;
	};
}

#endif