#include "Entity.h"
//#include <edpwin32.h>
//#include <rpc.h>

namespace Engine {
	
	Entity::Entity(std::string name) {
		_name = name;

		//GUID gidReference;
		//_GUID = UuidCreate(&gidReference);
	}

	

	long Entity::getGUID()
	{
		return _GUID;
	}

	Entity::~Entity() {
	}
}