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

	template<typename T>
	class Array2D {

	private:
		vector<Array2D<T>> _value;

	public:
		Array2D<T> const& operator[](T index) const
		{
			for (auto i = _value.begin(); i < _value.end(); i++)
			{
				if (*i == index) 
				{
					return _value[index];
				}
				else {
					//_value. [index]
				}

			}
		}
	};

	class SpriteAtlast
	{
	public:
		SpriteAtlast(Texture* tex, const int& tileSize);

		vector<vec2> getTileUV(int index);
		vector<vec2> getTileUV(int x, int y);

	private:
		typedef vector<vector<vector<glm::vec2>>> SpriteMatrix;

		map<pair<int, int>, vector<vec2>> _locations;
		unsigned int _tilesHorizontalCount;
		unsigned int _tilesVerticalCount;
		SpriteMatrix _matrix;

		SpriteMatrix getAtlasUVLocations(Texture* tex, int tileSize);
	};
}

