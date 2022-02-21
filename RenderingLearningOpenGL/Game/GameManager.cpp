#include "GameManager.h"
#include "../GameHelper.h"
#include "Enemy.h"
#include "Player.h"
#include "Background.h"
#include "GameTypes.h"
#include <iostream>
namespace Navecita {

	INIT_BEHAVIOUR(GameManager), _levelContainer(new LevelContainer())
	{
	}

	void GameManager::Update()
	{
		if (!_gameStarted && Input::_Space_Pressed) {
			_gameStarted = true;
			_initGame = true;
		}

		if (_initGame) {
			_initGame = false;

			_currentLevel = _levelContainer->GetLevelInfo(0);


			CreateGameEntity<Background>("Background", 16, 16)->GetTransform()->SetPosition(0, -5, 0);

			_player = CreateGameEntity<Player>("Player", 16, 16);
			_player->GetTransform()->SetPosition(0, -12, 0);

			auto bind = std::bind(&GameManager::EndGame, this);
			_player->getGameEntity()->OnDestroyedCallback(bind);
		}

		if (_gameStarted) {
			_enemySpawnTime -= 0.05f;

			if (_enemySpawnTime <= 0 && _enemyIndex < _currentLevel->_enemies.size()) {
				EnemyInfo enemyInf = _currentLevel->_enemies.at(_enemyIndex);

				Enemy* enemy = CreateGameEntity<Enemy>("Enemy", 16, 16);
				enemy->_life = enemyInf._life;
				enemy->GetTransform()->SetPosition({ enemyInf._spawnPos.x, enemyInf._spawnPos.y, 0 });

				_enemyIndex++;

				_enemySpawnTime = _currentLevel->_enemySpawnInterval;
			}
		}
	}

	void GameManager::OnRenderStart()
	{

	}

	void GameManager::OnCollision(GameEntity* entity)
	{

	}

	void GameManager::EndGame()
	{
		std::cout << "player dead" << "\n";
		_gameStarted = false;
	}

	GameManager::~GameManager()
	{

	}
}