#pragma once

#include "Transform.h"
#include "QuadRenderer.h"
#include "Camera.h"
#include <string>

namespace Engine {
	class Entity
	{
	public:
		QuadRenderer* _renderer;

		std::string _name;

		Entity(std::string);
		~Entity();
		void Bind(Camera* cam);

		Transform* getTransform() const {
			return _transform;
		}


	private:
		Transform* _transform;
	};
}


