#pragma once
#include "../Engine.h"
#include "LevelContainer.h"
#include "Player.h"

using namespace Engine;
namespace Navecita {

	class GameManager : GAME_BEHAVIOUR
	{
	public:
		DECLARE_BEHAVIOUR(GameManager)

		virtual void Update() override;
		virtual void OnRenderStart() override;
		virtual void OnCollision(GameEntity* entity) override;
		void EndGame();
	private:
		LevelContainer* _levelContainer = nullptr;
		LevelInfo* _currentLevel = nullptr;
		Player* _player = nullptr;
		bool _gameStarted = false;
		bool _initGame = false;
		float _enemySpawnTime = 0;
		float _enemyIndex = 0;
	};
}