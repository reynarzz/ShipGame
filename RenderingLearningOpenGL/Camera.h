#pragma once
#include <glm/glm.hpp>
#include "Transform.h"
#include "Entity.h"

namespace Engine {
	class Camera : public Entity
	{
	public:
		Camera(float n, float f, float fov);
		glm::mat4 getProj();
		glm::mat4 getView();

	private:
		Transform* _viewTransform;
		glm::mat4 _proj;
	};
}

