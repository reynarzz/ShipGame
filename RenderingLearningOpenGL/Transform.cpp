#include "Transform.h"

namespace Engine {
	Transform::Transform() {
		_position = glm::mat4(1.0f);
		_rotation = glm::mat4(1.0f);
		_scale = glm::mat4(1.0f);

		updateModelM();
	}

	Transform::~Transform() {

	}

	void Transform::SetPosition(glm::vec3 pos) 
	{
		_position = glm::translate(glm::mat4(1.0f), pos);

		_v_position = pos;

		updateModelM();
	}

	void Transform::SetPosition(float x, float y, float z) {
		SetPosition(glm::vec3(x, y, z));
	}

	glm::vec3 Transform::getPosition() const
	{
		return _v_position;
	}

	glm::mat4 Transform::getModelM() {
		return _modelM;
	}

	void Transform::updateModelM() {
		_modelM = _position * _rotation * _scale;
	}
}