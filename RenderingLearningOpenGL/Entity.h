#pragma once

#include "Transform.h"
#include "QuadRenderer.h"
#include "Camera.h"
#include <string>

namespace Engine {
	class Entity
	{
	public:

		std::string _name;

		Entity(std::string);
		~Entity();

		int getGUID();

	private:
		long _GUID;
	};
}


