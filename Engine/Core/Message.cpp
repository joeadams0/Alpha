/*
 * Message.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "Message.hpp"
#include <boost/functional/hash.hpp>

using namespace Panther;


std::string Message::ENTITY_CREATED = "engine_entity_created";
std::string Message::ENTITY_DESTROYED = "engine_entity_destroyed";
std::string Message::ENTITY_COMPOSITION_CHANGED = "engine_entity_composition_changed";

Message::Message(std::string messageName){
	this->messageName = messageName;
	messageType = getMessageType(messageName);
}

Message::~Message(){

}

std::string Message::getMessageName(){
	return messageName;
}

int Message::getMessageType(){
	return messageType;
}

int Message::getMessageType(std::string messageName){
	boost::hash<std::string> string_hash;
	return string_hash(messageName);
}