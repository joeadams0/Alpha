/*
 * SceneObject.hpp
 *
 *  Created on: May 3, 2014
 *      Author: Joe Adams
 */

#pragma once

#ifndef SCENEOBJECT_HPP_
#define SCENEOBJECT_HPP_

#include "Object.hpp"

namespace Panther {
	class Scene;

	// All classes inside a single scene should extend this
	class SceneObject : public Panther::Object
	{
	public:
		SceneObject();
		~SceneObject();

		virtual Panther::Scene* getScene();
		virtual void setScene(Panther::Scene* scene);

	protected:
		Panther::Scene* scene;
		
	};
}

#endif
