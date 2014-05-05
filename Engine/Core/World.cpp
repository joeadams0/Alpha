/*
 * World.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include <string>
#include <unordered_map>
#include "../Include/World.hpp"

using namespace Panther;

World::World(){
	scenes = new std::unordered_map<std::string, Scene*>();
	currentScene = NULL;
}

World::~World(){
	delete scenes;
}

void World::addScene(Scene* scene){
	scene->setWorld(this);
	
	if(!scene->isInit())
		scene->init();


	if(!currentScene){
		setCurrentScene(scene);
	}

	(*scenes)[scene->getSceneName()] = scene;
}

Scene* World::getScene(std::string sceneName){
	return (*scenes)[sceneName]; 
}

Scene* World::removeScene(std::string sceneName) {
	Scene* scene = this->getScene(sceneName);

	scenes->erase(sceneName);

	if(scene == currentScene){
		currentScene = NULL;

		if(scenes->size()>0){
			
			std::unordered_map<std::string, Scene*>::iterator it = scenes->begin();

			currentScene = it->second;

		}
	}

	return scene;
}

void World::transitionScene(std::string sceneName){
	currentScene->sleep();

	setCurrentScene(scenes->at(sceneName));
}

Scene* World::getCurrentScene(){
	return currentScene;
}

void World::setCurrentScene(Scene* scene){
	scene->awake();
	currentScene = scene;
}

void World::process(){
	currentScene->process();
}


