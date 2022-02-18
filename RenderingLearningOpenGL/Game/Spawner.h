#pragma once
#include "Enemy.h"
#include "Player.h"

class Spawner
{
	enum class EnemyType {
		Red, Green, White, Boss1, Boss2
	};

	enum class ProjectileType {
		Red, Yellow
	};


	void SpawnEnemy(const EnemyType& type);
	void SpawnPlayer();
	void SpawnProjectile(const std::string& target, ProjectileType type);
};