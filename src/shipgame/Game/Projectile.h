#pragma once
#include "../Engine.h"
#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"

using namespace Engine;

namespace Navecita {
	class Projectile : public EntityBehaviour
	{
	public:
		float _angle;
		DECLARE_BEHAVIOUR(Projectile);

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
		bool _shooted = false;
	};
}
