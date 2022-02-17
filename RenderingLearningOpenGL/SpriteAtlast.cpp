#include "SpriteAtlast.h"

namespace Engine {
	SpriteAtlast::SpriteAtlast(Texture* tex, const int& spriteSize) : _tilesHorizontalCount(0), _tilesVerticalCount(0)
	{
		_locations = getAtlasUVLocations(tex, spriteSize);
	}

    vector<vec2> SpriteAtlast::getSpriteUVLoc(int index)
    {
		/*map<pair<int, int>, vector<vec2>>::iterator it = _locations.begin();
		vector<vec2> element = (++it);
		
        return element;*/

		return vector<vec2>();
    }

    vector<vec2> Engine::SpriteAtlast::getSpriteUVLoc(int x, int y)
    {
		return _locations[pair<int, int>(x, y)];
    }

    map<pair<int, int>, vector<vec2>> SpriteAtlast::getAtlasUVLocations(Texture* tex, float tileSize)
    {
		map<pair<int, int>, vector<vec2>> locations;

		int width = tex->getWidth();
		int height = tex->getHeight();
		_tilesHorizontalCount = width / tileSize;
		_tilesVerticalCount = height / tileSize;

		for (int x = 0; x < _tilesHorizontalCount; x++)
		{
			for (int y = 0; y < _tilesVerticalCount; y++)
			{
				vector<vec2> atlasTexCoord;
				atlasTexCoord.push_back(vec2((x * tileSize) / width, (y * tileSize) / height));
				atlasTexCoord.push_back(vec2(((x + 1.0f) * tileSize) / width, (y * tileSize) / height));
				atlasTexCoord.push_back(vec2(((x + 1.0f) * tileSize) / width, ((y + 1.0f) * tileSize) / height));
				atlasTexCoord.push_back(vec2((x * tileSize) / width, ((y + 1.0f) * tileSize) / height));

				locations.insert({ std::pair<int, int>(x, y), atlasTexCoord });
			}
		}

		return locations;
    }
}
