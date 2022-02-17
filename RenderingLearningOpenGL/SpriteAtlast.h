#pragma once
#include <vector>
#include <map>
#include <glm/glm.hpp>
#include "Texture.h"


using glm::vec2;
using std::vector;
using std::map;
using std::pair;

namespace Engine {
	class SpriteAtlast
	{
	public:
		SpriteAtlast(Texture* tex, const int& tileSize);
		
		vector<vec2> getTileUV(int index);
		vector<vec2> getTileUV(int x, int y);

	private:
		map<pair<int, int>, vector<vec2>> _locations;
		unsigned int _tilesHorizontalCount;
		unsigned int _tilesVerticalCount;

		map<std::pair<int, int>, vector<vec2>> getAtlasUVLocations(Texture* tex, float tileSize);
	};
}

