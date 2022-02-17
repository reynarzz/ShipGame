#pragma once

#include "../EntityBehaviour.h"
#include "../SpriteAnimation.h"
#include "../SpriteAtlast.h"
#include "../Input.h"

using namespace Engine;

namespace Navecita {
	class Player : public EntityBehaviour
	{
	public:
		float _angle;
		Player(GameEntity* entity);

		void Update() override;
		void Start() override;
		void FixedUpdate() override;
		void SetInput_Test(KeyboardInput* input);
	private:
		SpriteAnimation* _anim;
		KeyboardInput* _input;
	};
}

