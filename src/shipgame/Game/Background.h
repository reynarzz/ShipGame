#pragma once

#include "../EntityBehaviour.h"

using namespace Engine;

namespace Navecita {
	class Background : public EntityBehaviour
	{
	public:
		Background(GameEntity* entity);

		void OnRenderStart() override;
		void Update() override;
		void OnCollision(GameEntity* entity) override;
	private:
		glm::vec2 _scroll;
		Material* _mat;
	};
}


