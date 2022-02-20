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
		void SetOrtho(float left, float right, float bottom, float top);
		glm::mat4 getProj();
		glm::mat4 getProjInv();
		glm::mat4 getView();
		glm::mat4 getViewInv();
		
		Transform* _viewTransform;

	private:
		glm::mat4 _proj;
		glm::mat4 _projInv;
	};
}