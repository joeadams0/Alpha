/*
 * EntityDestroyedEvent.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_DESTROYED_EVENT_HPP_
#define ENTITY_DESTROYED_EVENT_HPP_

#include "../Include/Event.hpp"

namespace Panther {
	class Entity;

	class EntityDestroyedEvent : public Panther::Event
	{
	public:
		EntityDestroyedEvent(Panther::Entity* destroyedEntity);
		~EntityDestroyedEvent();
		
		Panther::Entity* getDestroyedEntity();

	protected:
		Panther::Entity* destroyedEntity;
	};
}


#endif
