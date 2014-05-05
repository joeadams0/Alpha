/*
 * EventManager.hpp
 *
 *  Created on: May 5, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef EVENT_MANAGER_HPP_
#define EVENT_MANAGER_HPP_

#include <unordered_map>
#include <list>
#include <typeindex>
#include <typeinfo>

namespace Panther{

	class IEventListener;
	class Event;
	class EventManager
	{
	public:
		EventManager();
		~EventManager();
		
		template <class T> void addEventListener(Panther::IEventListener* listener){
			eventMap->at(std::type_index(typeid(T)))->push_back(listener);			
		}

		template <class T> void removeEventListener(Panther::IEventListener* listener){
			std::list<Panther::IEventListener*>* list = eventMap->at(std::type_index(typeid(T)));

			for(std::list<Panther::IEventListener*>::iterator it=list->begin(); it != list->end(); ++it){
				if((*it) == listener){
					list->erase(it);
				}
			}

		}

		template <class T> void removeAllEventListeners(){
			eventMap->erase(std::type_index(typeid(T)));
		}

		void fireEvent(Panther::Event* event);

	protected:
		std::unordered_map<std::type_index, std::list<Panther::IEventListener*>*>* eventMap;

	};

}

#endif