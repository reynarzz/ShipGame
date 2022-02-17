#pragma once
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

namespace Engine {
	class Transform
	{
	public:
		Transform();
		~Transform();
		void SetPosition(glm::vec3);
		void SetPosition(float x, float y, float z);

		void SetRotation(glm::vec3);
		void SetRotation(float x, float y, float z);

		void SetScale(glm::vec3);
		void SetScale(float x, float y, float z);

		 glm::vec3 getPosition() const;
		 glm::vec3 getRotation() const;
		 glm::vec3 getScale() const;

		 glm::mat4 getModelM();

	private:
		glm::mat4 _position;
		glm::mat4 _rotation;
		glm::mat4 _scale;


		glm::vec3 _v_position;
		glm::vec3 _v_rotation;
		glm::vec3 _v_scale;

		glm::mat4 _modelM;

		void updateModelM();
	};
}
