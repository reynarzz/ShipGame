#include "Entity.h"

namespace Engine {
	Entity::Entity(std::string name) {
		_name = name;
		_transform = new Transform();
	}

	Entity::~Entity() {
		delete _transform;
	}

	void Entity::Bind(Camera* cam)
	{
		_renderer->Bind(_transform->getModelM(), cam->getView(), cam->getProj());
	}
}