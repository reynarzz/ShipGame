#pragma once

#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"

using namespace Engine;

namespace Navecita {
	class StonePixel : public EntityBehaviour
	{
	public:
		float _angle;
		StonePixel(GameEntity* entity);

		void Update() override;
		void SetTarget(const std::string& target);
		void OnRenderStart() override;
		void Shoot(glm::vec2 startPos, glm::vec2 dir, float speed);
		void OnCollision(GameEntity* entity) override;

	private:
		SpriteAnimation* _anim;
		glm::vec2 _moveDir;
		float _speed;
		std::string _target;
		float _autoDestroyCurrent;
	};
}
