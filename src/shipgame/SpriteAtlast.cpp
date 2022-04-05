#include "SpriteAtlast.h"

namespace Engine {
	SpriteAtlast::SpriteAtlast(Texture* tex, const int& spriteSize) : _tilesHorizontalCount(0), _tilesVerticalCount(0)
	{
		_matrix = getAtlasUVLocations(tex, spriteSize);
	}

    vector<vec2> SpriteAtlast::getTileUV(int index)
    {
		/*map<pair<int, int>, vector<vec2>>::iterator it = _locations.begin();
		vector<vec2> element = (++it);
		
        return element;*/

		return vector<vec2>();
    }

    vector<vec2> Engine::SpriteAtlast::getTileUV(int x, int y)
    {
		return _matrix[x][y];
    }


	SpriteAtlast::SpriteMatrix SpriteAtlast::getAtlasUVLocations(Texture* tex, int tileSize)
    {
		float width = tex->getWidth();
		float height = tex->getHeight();
		_tilesHorizontalCount = width / tileSize;
		_tilesVerticalCount = height / tileSize;

		SpriteAtlast::SpriteMatrix matrix;
		for (int x = 0; x < _tilesHorizontalCount; x++)
		{
			vector<vector<glm::vec2>> column;

			for (int y = 0; y < _tilesVerticalCount; y++)
			{
				vector<vec2> atlasTexCoord;
				atlasTexCoord.push_back(vec2((x * tileSize) / width, (y * tileSize) / height));
				atlasTexCoord.push_back(vec2(((x + 1.0f) * tileSize) / width, (y * tileSize) / height));
				atlasTexCoord.push_back(vec2(((x + 1.0f) * tileSize) / width, ((y + 1.0f) * tileSize) / height));
				atlasTexCoord.push_back(vec2((x * tileSize) / width, ((y + 1.0f) * tileSize) / height));

				column.push_back(atlasTexCoord);
			}

			matrix.push_back(column);
		}

		return matrix;
    }
}
