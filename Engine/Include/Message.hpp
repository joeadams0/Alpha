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
#include "Entity.hpp"
#include "Component.hpp"

namespace Panther{

	typedef boost::variant<bool, int, Panther::uint, std::string> MessageVar;

	class Message : public Panther::Object
	{
	public:
		Message(std::string messageName);
		~Message();

		template <class T> T getProperty(std::string name){
			return boost::get<T>(properties[name]);
		}

		template <typename T> void setProperty(std::string name, T value){
			MessageVar v = value;
			properties[name] = value;
		}
		
		std::string getMessageName();
		int getMessageType();

		static int getMessageType(std::string messageName);
		
	protected:
		std::unordered_map<std::string, Panther::MessageVar> properties;
		int messageType;
		std::string messageName;
	};

}

#endif