/*
 * EntitySystem.hpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_SYSTEM_HPP_
#define ENTITY_SYSTEM_HPP_

#include "System.hpp"
#include "IMessageListener.hpp"

namespace Panther{

	class EntitySystem : public Panther::System, Panther::IMessageListener
	{
	public:
		EntitySystem();
		~EntitySystem();
		
		virtual void awake();
		virtual void handleMessage(Panther::Message* Message);

	
	};
}

#endif