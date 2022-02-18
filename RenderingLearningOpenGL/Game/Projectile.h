#pragma once

#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"
#include "../AABB.h"

using namespace Engine;

namespace Navecita {
	class Projectile : public EntityBehaviour
	{
	public:
		float _angle;
		Projectile(GameEntity* entity);

		void Update() override;
		void Start() override;
		void FixedUpdate() override;
		void Shoot(glm::vec2 startPos, glm::vec2 dir, float speed);
		AABB* _aabb;
	private:
		SpriteAnimation* _anim;
		glm::vec2 _moveDir;
		float _speed;
	};
}
