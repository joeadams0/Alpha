/*
 * SystemManager.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "../Include/SystemManager.hpp"
#include "../Include/System.hpp"

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
	(*systems)[system->getTypeIndex<System>(system)] = system;
}