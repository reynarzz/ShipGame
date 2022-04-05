#pragma once
#include "../Engine.h"
#include "LevelContainer.h"
#include "Player.h"
#include "Enemy.h"
#include "Background.h"
#include "Fade.h"

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

		void OnFadeIn();
		void OnFadeOut();
	private:
		LevelContainer* _levelContainer = nullptr;
		LevelInfo* _currentLevel = nullptr;
		Player* _player = nullptr;
		vector<Enemy*> _enemies;
		Background* _background = nullptr;
		Fade* _fade;


		bool _gameStarted = false;
		bool _initGame = false;
		float _enemySpawnTime = 0;
		float _enemyIndex = 0;
	};
}