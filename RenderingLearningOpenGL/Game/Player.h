#pragma once
#include "../Engine.h"
#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"
#include "../Input.h"
#include "../AABB.h"

using namespace Engine;

namespace Navecita {
	class Player : public EntityBehaviour
	{
	public:
		DECLARE_BEHAVIOUR(Player)

		void Shoot();
		void OnCollision(GameEntity* name) override;
		void SetDestroyableTex(Texture* tex);

	private:
		SpriteAnimation* _anim = nullptr;
		const float _shootInterval = 0.02f;
		float _sootTime = 0.0f;
		int _life = 0;
	};
}

