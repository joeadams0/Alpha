/*
 * MessageManager.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef Message_MANAGER_HPP_
#define Message_MANAGER_HPP_

#include <map>

namespace Panther{

	class IMessageListener;
	class Message;
	class MessageManager
	{
	public:
		MessageManager();
		~MessageManager();
		
		void addMessageListener(std::string messageName, Panther::IMessageListener* listener);

		void removeMessageListener(std::string messageName, Panther::IMessageListener* listener);

		void removeAllMessageListeners(std::string messageName);

		void sendMessage(Panther::Message* Message);

	protected:
		std::multimap<int, Panther::IMessageListener*> messageListenerMap;

	};

}

#endif