/*
 * Message.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef Message_HPP_
#define Message_HPP_




#include <unordered_map>
#include <string>
#include <boost/variant.hpp>
#include "Object.hpp"

namespace Panther{

	class Entity;
	class Component;

	typedef boost::variant<bool, int, Panther::uint, std::string, Panther::Entity*, Panther::Component*> MessageVar;

	class Message : public Panther::Object
	{
	public:
		Message(std::string messageName);
		~Message();

		template <typename T> T getProperty(std::string name){
			return boost::get<T>(properties[name]);
		}

		template <typename T> void setProperty(std::string name, T value){
			MessageVar v = value;
			properties[name] = value;
		}
		
		std::string getMessageName();
		int getMessageType();


		static int getMessageType(std::string messageName);

		static std::string ENTITY_CREATED;
		static std::string ENTITY_DESTROYED;
		static std::string ENTITY_COMPOSITION_CHANGED;


		
	protected:
		std::unordered_map<std::string, Panther::MessageVar> properties;
		int messageType;
		std::string messageName;
	};

}



#endif