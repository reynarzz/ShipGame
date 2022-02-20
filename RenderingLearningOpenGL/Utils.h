#pragma once
#include <glm/glm.hpp>

#include <vector>
#include "Mesh.h"
#include <map>
#include  "Texture.h"
using glm::ivec2;
using glm::vec2;
using std::map;

namespace Engine {
	class Utils {
	public:
		static Mesh* GetQuadMesh(float x = 1.0f, float y = 1.0f) {

			vector<vec3> verts;
			verts.push_back(vec3(-1.0f * x, -1.0f * y, 0.0) );
			verts.push_back(vec3(1.0 * x, -1.0 * y, 0.0) );
			verts.push_back(vec3(1.0 * x, 1.0 * y, 0.0));
			verts.push_back(vec3(-1.0 * x, 1.0 * y, 0.0));

			vector<unsigned int> indices;
			indices.push_back(0);
			indices.push_back(1);
			indices.push_back(2);

			indices.push_back(0);
			indices.push_back(2);
			indices.push_back(3);

			vector<vec2> uv;
			uv.push_back(vec2(0.0f, 0.0f));
			uv.push_back(vec2(1.0f, 0.0f));
			uv.push_back(vec2(1.0f, 1.0f));
			uv.push_back(vec2(0.0f, 1.0f));

			return new Mesh(verts, indices, uv);
		}

		static map<std::pair<int, int>, vector<vec2>> getAtlasUVLocations(Texture* tex, float tileSize) {

			std::map<std::pair<int, int>, vector<vec2>> locations;

			int width = tex->getWidth();
			int height = tex->getHeight();
			int row = width / tileSize;
			int col = height / tileSize;

			for (int x = 0; x < row; x++)
			{
				for (int y = 0; y < col; y++)
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

		static float Normalize(float val, float max, float min) 
		{
			return (val - min) / (max - min); 
		}
	};
}