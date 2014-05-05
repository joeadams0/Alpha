/*
 * World.hpp
 *
 *  Created on: May 1, 2014
 *      Author: Joe Adams
 */

#pragma once
 
#ifndef WORLD_HPP_
#define WORLD_HPP_

#include <string>
#include <unordered_map>
#include "Scene.hpp"
#include "Object.hpp"

namespace Panther {

	class World : public Panther::Object {
	public:
		World();
		~World();
		
		void addScene(Panther::Scene* scene);
		Panther::Scene* getScene(std::string sceneName);
		Panther::Scene* removeScene(std::string sceneName);
		Panther::Scene* getCurrentScene();
		void transitionScene(std::string sceneName);

		// Process the current scene for one frame
		void process();

	protected:
		std::unordered_map<std::string, Panther::Scene*>* scenes;
		Panther::Scene* currentScene;

		void setCurrentScene(Panther::Scene* scene);
	};
}


#endif /* WORLD_HPP_ */
