/*
 * SystemManager.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "SystemManager.hpp"
#include "System.hpp"

using namespace Panther;

SystemManager::SystemManager(){
	systems = new std::unordered_map<std::type_index, System*>();
}

SystemManager::~SystemManager(){
	delete systems;
}

void SystemManager::process(){
	for(auto it = systems->begin(); it != systems->end(); ++it ){
		it->second->process();
	}
}

void SystemManager::addSystem(System* system){
	system->setScene(getScene());
	system->awake();
	(*systems)[system->getTypeIndex()] = system;
}

void SystemManager::awake(){
	for(auto it = systems->begin(); it != systems->end(); ++it ){
		it->second->awake();
	}	
}

void SystemManager::sleep(){
	for(auto it = systems->begin(); it != systems->end(); ++it ){
		it->second->sleep();
	}
}