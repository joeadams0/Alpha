/*
 * Component.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef COMPONENT_HPP_
#define COMPONENT_HPP_

#include "SceneObject.hpp"

namespace Panther {
	class Entity;

	class Component : public Panther::SceneObject
	{
	public:
		Component();
		~Component();

		Panther::Entity* getEntity();

	protected:
		Panther::Entity* __entity;
		
	};
}

#endif