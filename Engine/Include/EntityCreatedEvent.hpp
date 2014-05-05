/*
 * EntityCreatedEvent.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_CREATED_EVENT_HPP_
#define ENTITY_CREATED_EVENT_HPP_

#include "../Include/Event.hpp"

namespace Panther {
	class Entity;

	class EntityCreatedEvent : public Panther::Event
	{
	public:
		EntityCreatedEvent(Panther::Entity* createdEntity);
		~EntityCreatedEvent();
		
		Panther::Entity* getCreatedEntity();

	protected:
		Panther::Entity* createdEntity;
	};
}


#endif
