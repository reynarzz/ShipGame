#include "GameManager.h"
#include "../GameHelper.h"
#include "GameTypes.h"
#include <iostream>

namespace Navecita {

	INIT_BEHAVIOUR(GameManager), _levelContainer(new LevelContainer())
	{
		_fade = CreateGameEntity<Fade>("FadeScreen", 1024, 1024);
		_fade->GetTransform()->SetPosition(0, 0, -4);

		auto fadeInCall = std::bind(&GameManager::OnFadeIn, this);
		auto fadeOutCall = std::bind(&GameManager::OnFadeOut, this);


		_fade->OnFadeIn(fadeInCall);
		_fade->OnFadeOut(fadeOutCall);
	}

	void GameManager::Update()
	{
		if (!_gameStarted && Input::_Space_Pressed) {
			_fade->FadeOut();

			_gameStarted = true;
			_initGame = true;
		}

		if (_initGame) {
			_initGame = false;

			_currentLevel = _levelContainer->GetLevelInfo(0);

			_background = CreateGameEntity<Background>("Background", 16, 16);
			_background->GetTransform()->SetPosition(0, -5, 0);

			_player = CreateGameEntity<Player>("Player", 16, 16);
			_player->GetTransform()->SetPosition(0, -12, 2);

			auto bind = std::bind(&GameManager::EndGame, this);
			_player->getGameEntity()->OnDestroyedCallback(bind);
		}

		if (_gameStarted) {
			_enemySpawnTime -= 0.05f;

			if (_enemySpawnTime <= 0 && _enemyIndex < _currentLevel->_enemies.size()) {
				EnemyInfo enemyInf = _currentLevel->_enemies.at(_enemyIndex);

				Enemy* enemy = CreateGameEntity<Enemy>("Enemy", 16, 16);
				enemy->_life = enemyInf._life;
				enemy->GetTransform()->SetPosition({ enemyInf._spawnPos.x, enemyInf._spawnPos.y, 3 });

				_enemies.push_back(enemy);
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
		_fade->FadeIn();
		
	}

	void GameManager::OnFadeIn()
	{
		//DestroyEntity(_background->getGameEntity());

		////_background = nullptr;
		////_player = nullptr;

		//for (size_t i = 0; i < _enemies.size(); i++)
		//{
		//	DestroyEntity(_enemies.at(0)->getGameEntity());
		//}

		//_enemies.clear();

		//_fade->FadeOut();
		_gameStarted = false;

	}

	void GameManager::OnFadeOut()
	{
		_gameStarted = true;
	}

	GameManager::~GameManager()
	{

	}
}