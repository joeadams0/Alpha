/*
 * World.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include <string>
#include <cstdarg>
#include <unordered_map>
#include <emscripten.h>
#include "World.hpp"

using namespace Panther;

bool World::created = false;
World* World::instance = NULL;
int World::fps = 0;

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

void World::start(){
	if(mainLoopSet){
		emscripten_resume_main_loop();
		mainLoopSet = true;
	}
	else
		emscripten_set_main_loop(World::processInstance, fps, 1);
}

void World::pause(){
	emscripten_pause_main_loop();
}

World* World::getInstance(){
	if(!created){
		instance = new World();
		created = true;
	}
	return instance;
}

void World::processInstance(){
	getInstance()->process();
}

void World::setFps(int fps){
	World::fps = fps;
}



