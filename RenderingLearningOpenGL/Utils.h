#include "Mesh.h"

#pragma once
namespace Engine {
	class Utils {
	public:
		static Mesh* GetQuadMesh(float x = 1.0f, float y = 1.0f) {

			vector<vec3> verts;
			verts.push_back(glm::vec3(-1.0f * x, -1.0f * y, 0.0) );
			verts.push_back(glm::vec3(1.0 * x, -1.0 * y, 0.0) );
			verts.push_back(glm::vec3(1.0 * x, 1.0 * y, 0.0));
			verts.push_back(glm::vec3(-1.0 * x, 1.0 * y, 0.0));

			vector<unsigned int>* indices = new vector<unsigned int>();
			indices->push_back(0);
			indices->push_back(1);
			indices->push_back(2);

			indices->push_back(0);
			indices->push_back(2);
			indices->push_back(3);

			vector<glm::vec2> uv;
			uv.push_back(glm::vec2(0.0f, 0.0f));
			uv.push_back(glm::vec2(1.0f, 0.0f));
			uv.push_back(glm::vec2(1.0f, 1.0f));
			uv.push_back(glm::vec2(0.0f, 1.0f));

			return new Mesh(verts, indices, uv);
		}
	};
}