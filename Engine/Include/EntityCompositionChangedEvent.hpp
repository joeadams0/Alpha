/*
 * EntityCompositionChangedEvent.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef ENTITY_COMPOSITION_CHANGED_EVENT_HPP_
#define ENTITY_COMPOSITION_CHANGED_EVENT_HPP_

#include "../Include/Event.hpp"

namespace Panther {
	class Entity;

	class EntityCompositionChangedEvent : public Panther::Event
	{
	public:
		EntityCompositionChangedEvent(Panther::Entity* changedEntity);
		~EntityCompositionChangedEvent();
		
		Panther::Entity* getChangedEntity();

	protected:
		Panther::Entity* changedEntity;
	};
}


#endif
