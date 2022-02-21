#pragma once
#include "GameTypes.h"

namespace Navecita {
	class LevelContainer
	{
	public:
		LevelContainer();
		~LevelContainer();

		LevelInfo* GetLevelInfo(int index) const;
		int GetLevelsCount() const;
	private:
		vector<LevelInfo*>* _levelsInfo = nullptr;
	};
}
