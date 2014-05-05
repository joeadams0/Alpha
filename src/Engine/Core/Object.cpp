/*
 * Object.cpp
 *
 *  Created on: May 2, 2014
 *      Author: Joe Adams
 */
  
#include "../Include/Object.hpp"

using namespace Panther;

Object::Object(){}

Object::~Object(){}

bool operator==(Object& obj1, Object& obj2){
	return obj1==obj2;
}

std::string JSONSerialize(){
	std::string json = "";

	return json;
}

Object* JSONDeserialize(std::string json, Object* obj){
	if(!obj)
		obj = new Object();

	return obj;
}