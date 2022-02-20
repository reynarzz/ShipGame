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
	
	void Transform::SetPosition(float x, float y, float z)
	{
		SetPosition(glm::vec3(x, y, z));
	}

	void Transform::SetPosition(glm::vec3 pos)
	{
		/*float xFract = round(glm::fract(pos.x));
		float yFract = round(glm::fract(pos.y));

		pos.x = round(pos.x) + xFract;
		pos.y = round(pos.y) + yFract;*/

		_v_position = pos;

		_position = glm::translate(glm::mat4(1.0f), _v_position);

		updateModelM();
	}

	
	void Transform::SetRotation(float x, float y, float z)
	{
		SetRotation(glm::vec3(x, y, z));
	}

	void Transform::SetRotation(glm::vec3 angle)
	{
		glm::mat4 xRot = glm::rotate(glm::mat4(1.0f), angle.x, glm::vec3(1, 0, 0));
		glm::mat4 yRot = glm::rotate(glm::mat4(1.0f), angle.y, glm::vec3(0, 1, 0));
		glm::mat4 zRot = glm::rotate(glm::mat4(1.0f), angle.z, glm::vec3(0, 0, 1));

		_rotation = zRot * yRot * xRot;

		updateModelM();
	}

	void Transform::SetScale(glm::vec3 scale)
	{
		_scale = glm::scale(glm::mat4(1.0), scale);
		updateModelM();
	}

	void Transform::SetScale(float x, float y, float z)
	{
		SetScale(glm::vec3(x, y, z));
	}

	glm::vec3 Transform::getPosition() const
	{
		return _v_position;
	}

	glm::mat4 Transform::getModelM() {
		return _modelM;
	}

	glm::mat4 Transform::getModelMInv() {
		return _modelMInv;
	}


	void Transform::updateModelM() {
		_modelM = _position * _rotation * _scale;
		_modelMInv = glm::inverse(_modelM);
	}
}