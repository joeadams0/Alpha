/*
 * Scene.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "Scene.hpp"
#include "EntityManager.hpp"
#include "ComponentManager.hpp"
#include "Manager.hpp"

using namespace Panther;

Scene::Scene(std::string sceneName){
	this->sceneName = sceneName;
	world = NULL;
	managers = new std::unordered_map<std::type_index, Manager*>();
	_awake = false;
	_init = false;
}

Scene::~Scene(){
	delete managers;
}

void Scene::init(){
	_init = true;

	addManager(new EntityManager());
	addManager(new ComponentManager());
	addManager(new SystemManager());
}

void Scene::awake(){
	_awake = true;
	for(auto it = managers->begin(); it != managers->end(); ++it ){
		it->second->awake();
	}
}

void Scene::sleep(){
	_awake = false;

	for(auto it = managers->begin(); it != managers->end(); ++it ){
		it->second->sleep();
	}
}

bool Scene::isAwake(){
	return _awake;
}

bool Scene::isInit(){
	return _init;
}

/**
 * Entities
 */

Entity* Scene::createEntity(){
	return getEntityManager()->createEntity();
}

Entity* Scene::getEntityByName(std::string name){
	return getEntityManager()->getEntityByName(name);
}

Entity* Scene::getEntityById(uint id){
	return getEntityManager()->getEntityById(id);
}


void Scene::addSystem(System* system){
	getSystemManager()->addSystem(system);
}

/**
 * Managers
 */

void Scene::addManager(Manager* manager){
	manager->setScene(this);
	(*managers)[manager->getTypeIndex<Manager>(manager)] = manager;
}


std::string Scene::getSceneName(){
	return sceneName;
}

SystemManager* Scene::getSystemManager(){
	return getManager<SystemManager>();
}

ComponentManager* Scene::getComponentManager(){
	return getManager<ComponentManager>();
}

EntityManager* Scene::getEntityManager(){
	return getManager<EntityManager>();
}

World* Scene::getWorld(){
	return world;
}

void Scene::setWorld(World* w){
	world = w;
}

void Scene::process(){
	for(auto it = managers->begin(); it != managers->end(); ++it ){
		it->second->process();
	}
}



