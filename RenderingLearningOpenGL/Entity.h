#pragma once

#include <string>

namespace Engine {
	class Entity
	{
	public:
		std::string _name;

		Entity(std::string);
		~Entity();

		long getGUID();

	private:
		long _GUID;
	};
}


