#pragma once

#include "Component.h"
#include "GameEntity.h"

namespace Engine {
	class EntityBehaviour : public Component
	{
	public:
		EntityBehaviour(GameEntity* gameEntity);

		virtual void Update();
		virtual void OnRenderStart();
		Transform* GetTransform() const;

		GameEntity* getGameEntity();
		virtual void OnCollision(GameEntity* entity);
	private:
		GameEntity* _gameEntity;
		
	};
}