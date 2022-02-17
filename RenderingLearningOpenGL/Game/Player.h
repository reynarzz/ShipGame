#pragma once

#include "../EntityBehaviour.h"

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
	};
}

