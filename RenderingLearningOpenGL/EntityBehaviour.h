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
		virtual void OnRenderStart() = 0;
		Transform* GetTransform() const;
		void OnDestroyed();

		GameEntity* getGameEntity();
		virtual void OnCollision(GameEntity* entity) = 0;
	private:
		GameEntity* _gameEntity;
	};
}