#include "LevelContainer.h"
namespace Navecita {
	LevelContainer::LevelContainer() : _levelsInfo(new vector<LevelInfo*>())
	{
		auto level = new LevelInfo();

		level->_enemySpawnInterval = 2;

		for (size_t i = 0; i < 50; i++)
		{
			EnemyInfo enemy;
			enemy._spawnPos = {rand() % 14, 16 };
			enemy._life = 5;
			level->_enemies.push_back(enemy);
		}

		_levelsInfo->push_back(level);
	}

	LevelContainer::~LevelContainer()
	{
	}

	LevelInfo* LevelContainer::GetLevelInfo(int index) const
	{
		return _levelsInfo->at(index);
	}

	int LevelContainer::GetLevelsCount() const
	{
		return _levelsInfo->size();
	}

}
