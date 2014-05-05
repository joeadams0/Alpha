/*
 * EntityComposition.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "../Include/EntityComposition.hpp"
#include "../Include/Entity.hpp"

using namespace Panther;

EntityComposition::EntityComposition(){
	allSet = new std::vector<bool>();
	someSet = new std::vector<bool>();
	noneSet = new std::vector<bool>();
}

EntityComposition::~EntityComposition(){
	delete allSet;
	delete someSet;
	delete noneSet;
}

std::vector<bool>* EntityComposition::getAllSet(){
	return allSet;
}

std::vector<bool>* EntityComposition::getSomeSet(){
	return someSet;
}

std::vector<bool>* EntityComposition::getNoneSet(){
	return noneSet;
}

bool EntityComposition::matches(std::vector<bool>* composition){
	bool matches = true;

	matches = matches || matchesAllSet(composition);
	matches = matches || matchesSomeSet(composition);
	matches = matches || matchesNoneSet(composition);

	return matches;
}

bool EntityComposition::matchesAllSet(std::vector<bool>* set){
	for (int i = 0; i < set->size(); ++i)
	{
		if((!set->at(i) && allSet->at(i)) || (set->at(i) && !allSet->at(i)))
			return false;
	}
	return true;
}

bool EntityComposition::matchesSomeSet(std::vector<bool>* set){

	for (int i = 0; i < set->size(); ++i)
	{
		if(set->at(i) && someSet->at(i))
			return true;
	}

	return false;
}

bool EntityComposition::matchesNoneSet(std::vector<bool>* set){

	for (int i = 0; i < set->size(); ++i)
	{
		if(set->at(i) && noneSet->at(i))
			return false;
	}
	return true;
}


