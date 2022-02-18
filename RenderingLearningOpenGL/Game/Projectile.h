#pragma once

#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"

using namespace Engine;

namespace Navecita {
	class Projectile : public EntityBehaviour
	{
	public:
		float _angle;
		Projectile(GameEntity* entity);

		void Update() override;
		void Start() override;
		void OnRenderStart() override;
		void Shoot(glm::vec2 startPos, glm::vec2 dir, float speed);
		void OnCollision(GameEntity* entity) override;

	private:
		SpriteAnimation* _anim;
		glm::vec2 _moveDir;
		float _speed;
	};
}
