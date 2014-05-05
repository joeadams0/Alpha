/*
 * IEventListener.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef EVENT_LISTENER_HPP_
#define EVENT_LISTENER_HPP_

namespace Panther{

	class Event;
	
	class IEventListener
	{
	public:
		virtual ~IEventListener();

		virtual void action(Panther::Event* event) = 0;
		
	};
}

#endif