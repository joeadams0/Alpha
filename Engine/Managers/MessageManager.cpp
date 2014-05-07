/*
 * MessageManager.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "MessageManager.hpp"
#include "Message.hpp"
#include "IMessageListener.hpp"

using namespace Panther;

 MessageManager::MessageManager(){

 }

 MessageManager::~MessageManager(){

 }

 void MessageManager::sendMessage(Message* message){
 	typedef std::multimap<int,IMessageListener*>::iterator iterator;
 	std::pair <iterator, iterator> itpair = messageListenerMap.equal_range(message->getMessageType());

 	iterator it = itpair.first;

 	for (; it != itpair.second; ++it) {
	    it->second->handleMessage(message);
	}
 }

 void MessageManager::addMessageListener(std::string messageName, IMessageListener* listener){
 	messageListenerMap.insert(std::pair<int, IMessageListener*>(Message::getMessageType(messageName), listener));
 }

 void MessageManager::removeMessageListener(std::string messageName, IMessageListener* listener){
 	typedef std::multimap<int,IMessageListener*>::iterator iterator;
 	std::pair <iterator, iterator> itpair = messageListenerMap.equal_range(Message::getMessageType(messageName));

 	iterator it = itpair.first;

 	for (; it != itpair.second; ++it) {
	    if (it->second == listener) { 
	        messageListenerMap.erase(it);
	        break;
	    }
	}

 }

 void MessageManager::removeAllMessageListeners(std::string messageName){
	messageListenerMap.erase(Message::getMessageType(messageName)); 	
 }