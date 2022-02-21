#pragma once
#include <vector>
#include <glm/glm.hpp>
using std::vector;

namespace Navecita {
	enum class EnemyType {
		Normal, Circle, Triangle
	};

	class EnemyInfo {
	public:
		int _life = 1;
		EnemyType _type = EnemyType::Normal;
		glm::vec2 _spawnPos;
	};

	class LevelInfo {
	public:
		float _enemySpawnInterval = 0;
		vector<EnemyInfo> _enemies;
	};
}
