/*
 * EntityComposition.cpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#include "EntityComposition.hpp"
#include "Entity.hpp"

using namespace Panther;

EntityComposition::EntityComposition(){
	allSet = new boost::dynamic_bitset<>(16);
	someSet = new boost::dynamic_bitset<>(16);
	noneSet = new boost::dynamic_bitset<>(16);
}

EntityComposition::~EntityComposition(){
	delete allSet;
	delete someSet;
	delete noneSet;
}

boost::dynamic_bitset<>* EntityComposition::getAllSet(){
	return allSet;
}

boost::dynamic_bitset<>* EntityComposition::getSomeSet(){
	return someSet;
}

boost::dynamic_bitset<>* EntityComposition::getNoneSet(){
	return noneSet;
}

bool EntityComposition::matches(boost::dynamic_bitset<>* composition){
	bool matches = true;

	matches = matches || matchesAllSet(composition);
	matches = matches || matchesSomeSet(composition);
	matches = matches || matchesNoneSet(composition);

	return matches;
}

bool EntityComposition::matchesAllSet(boost::dynamic_bitset<>* set){
	boost::dynamic_bitset<> newSet = (*set) & (*allSet);

	return newSet == (*allSet);
}

bool EntityComposition::matchesSomeSet(boost::dynamic_bitset<>* set){
	boost::dynamic_bitset<> newSet = (*set) & (*someSet);

	return newSet.any(); 
}

bool EntityComposition::matchesNoneSet(boost::dynamic_bitset<>* set){
	boost::dynamic_bitset<> newSet = (*set) & (*noneSet);

	return newSet.none();
}


