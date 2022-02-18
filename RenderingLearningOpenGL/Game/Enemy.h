#pragma once

#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"
#include "../AABB.h"

using namespace Engine;

namespace Navecita {
	class Enemy : public EntityBehaviour
	{
	public:
		float _angle;
		Enemy(GameEntity* entity);
		~Enemy();

		void Update() override;
		void Start() override;
		void OnRenderStart() override;
		void OnCollision(GameEntity* entity) override;

	private:
		SpriteAnimation* _anim;
	};
}

