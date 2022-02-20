#pragma once
#include "../EntityBehaviour.h"

using namespace Engine;
namespace Navecita {

	class GameManager : public EntityBehaviour
	{
	public:
		GameManager(GameEntity* gameEntity);
		~GameManager();


		// Inherited via EntityBehaviour
		virtual void Update() override;
		virtual void OnRenderStart() override;
		virtual void OnCollision(GameEntity* entity) override;
	};
}