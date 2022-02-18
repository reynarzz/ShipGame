#pragma once

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
		float _angle;
		Player(GameEntity* entity);

		void Update() override;
		void Start() override;
		void OnRenderStart() override;
		void SetInput_Test(KeyboardInput* input);
		void Shoot();
		void OnCollision(GameEntity* name) override;

	private:
		SpriteAnimation* _anim;
		KeyboardInput* _input;
		const float _shootInterval = 0.02f;
		float _sootTime = 0.0f;
	};
}

