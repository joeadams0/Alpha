/*
 * Object.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Joe Adams
 */
  
#include "Object.hpp"

using namespace Panther;

Object::Object(){}

Object::~Object(){}

bool operator==(Object& obj1, Object& obj2){
	return obj1==obj2;
}

std::string Object::JSONSerialize(){
	std::string json = "";

	return json;
}

Object* Object::JSONDeserialize(std::string json, Object* obj){
	if(!obj)
		obj = new Object();

	return obj;
}

std::type_index Object::getTypeIndex(){
	return std::type_index(typeid(*this));
}