/*
 * IMessageListener.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef Message_LISTENER_HPP_
#define Message_LISTENER_HPP_

namespace Panther{

	class Message;
	
	class IMessageListener
	{
	public:
		IMessageListener();
		~IMessageListener();

		virtual void handleMessage(Panther::Message* Message) = 0;
		
	};
}

#endif