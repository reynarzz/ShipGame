#pragma once

#include "Component.h"
#include "GameEntity.h"

namespace Engine {
	class EntityBehaviour : public Component
	{
	public:
		EntityBehaviour(GameEntity* gameEntity);

		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		void OnDestroyed();

		GameEntity* getGameEntity();

	private:
		GameEntity* _gameEntity;
	};
}