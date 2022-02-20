#include "GameManager.h"
#include "../GameHelper.h"
#include "Enemy.h"
#include "Player.h"
#include "Background.h"

namespace Navecita {

	GameManager::GameManager(GameEntity* gameEntity) : EntityBehaviour(gameEntity)
	{
	
	}

	GameManager::~GameManager() {

	}

	void GameManager::Update()
	{

	}

	void GameManager::OnRenderStart()
	{
		CreateGameEntity<Navecita::Background>("Background", 16, 16)->GetTransform()->SetPosition(0, -5, 0);

		CreateGameEntity<Navecita::Enemy>("Enemy", 16, 16)->GetTransform()->SetPosition({ -4, 3, 0 });
		CreateGameEntity<Navecita::Enemy>("Enemy", 16, 16)->GetTransform()->SetPosition({ 1, 10, 0 });
		CreateGameEntity<Navecita::Enemy>("Enemy", 16, 16)->GetTransform()->SetPosition({ 4, 15, 0 });
		CreateGameEntity<Navecita::Enemy>("Enemy", 16, 16)->GetTransform()->SetPosition({ 4, 12, 0 });

		Navecita::Player* player = CreateGameEntity<Navecita::Player>("Player", 16, 16);
		//player->SetInput_Test(_input);
		player->GetTransform()->SetPosition(0, -12, 0);
	}

	void GameManager::OnCollision(GameEntity* entity)
	{

	}
}

