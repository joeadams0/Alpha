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
		
		void addScene(Panther::Scene* scene);
		Panther::Scene* getScene(std::string sceneName);
		Panther::Scene* removeScene(std::string sceneName);
		Panther::Scene* getCurrentScene();
		void transitionScene(std::string sceneName);

		// Process the current scene for one frame
		virtual void process();

		virtual void start();
		virtual void pause();

		static Panther::World* getInstance();
		static void processInstance();
		static void setFps(int fps);



	protected:
		std::unordered_map<std::string, Panther::Scene*>* scenes;
		Panther::Scene* currentScene;


		World();
		~World();
		void setCurrentScene(Panther::Scene* scene);

		static Panther::World* instance;
		static bool created;
		bool mainLoopSet;
		static int fps;
	};
}


#endif /* WORLD_HPP_ */
