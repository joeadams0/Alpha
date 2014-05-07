/*
 * SceneObject.cpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#include "SceneObject.hpp"

using namespace Panther;

SceneObject::SceneObject(){
	scene = NULL;
}

SceneObject::~SceneObject(){

}

Scene* SceneObject::getScene(){
	return scene;
}

void SceneObject::setScene(Scene* scene){
	this->scene = scene;
}