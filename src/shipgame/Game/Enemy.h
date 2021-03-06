#pragma once
#include "../Engine.h"
#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"
#include "../AABB.h"

using namespace Engine;

namespace Navecita {
	class Enemy : public EntityBehaviour
	{
	public:
		int _life = 0;
		float _angle;
		DECLARE_BEHAVIOUR(Enemy);

		void Update() override;
		void OnRenderStart() override;
		void OnCollision(GameEntity* entity) override;

	private:
		SpriteAnimation* _anim;
	};
}

