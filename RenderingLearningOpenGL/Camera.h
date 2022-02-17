#pragma once
#include <glm/glm.hpp>
#include "Transform.h"
#include <glfw/glfw3.h>

namespace Engine {
	class Camera 
	{
	public:
		Camera();

		void SetProj(float fov, float aspect, float n, float f);
		glm::mat4 getProj();
		glm::mat4 getView();
		Transform* _viewTransform;

	private:
		glm::mat4 _proj;
	};
}