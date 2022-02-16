#pragma once
#include "Transform.h"
#include "QuadRenderer.h"

#include <string>

namespace Engine {
	class Entity
	{
	public:
		std::string _name;

		Entity(std::string);
		~Entity();

		Transform* getTransform() const {
			return _transform;
		}

	private:
		Transform* _transform;
	};
}


