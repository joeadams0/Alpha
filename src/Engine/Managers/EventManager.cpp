/*
 * EventManager.cpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#include "../Include/EventManager.hpp"
#include "../Include/Event.hpp"
#include "../Include/IEventListener.hpp"

using namespace Panther;

 EventManager::EventManager(){
 	eventMap = new std::unordered_map<std::type_index, std::list<Panther::IEventListener*>*>(); 
 }

 EventManager::~EventManager(){
 	delete eventMap;
 }

 void EventManager::fireEvent(Event* event){
 	std::list<Panther::IEventListener*>* list = eventMap->at(event->getTypeIndex<Event>(event));

 	for(std::list<Panther::IEventListener*>::iterator it=list->begin(); it != list->end(); ++it){
		(*it)->action(event);
	}
 }