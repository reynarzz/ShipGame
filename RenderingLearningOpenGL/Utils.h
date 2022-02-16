#include "Mesh.h"

#pragma once
namespace Engine {
	class Utils {
	public:
		static Mesh* GetQuadMesh(float physicalScale = 1.0f) {

			vector<vec3>* verts = new vector<glm::vec3>();
			verts->push_back(glm::vec3(-1.0f, -1.0f, 0.0) * physicalScale);
			verts->push_back(glm::vec3(1.0, -1.0, 0.0) * physicalScale);
			verts->push_back(glm::vec3(1.0, 1.0, 0.0) * physicalScale);
			verts->push_back(glm::vec3(-1.0, 1.0, 0.0) * physicalScale);

			vector<unsigned int>* indices = new vector<unsigned int>();
			indices->push_back(0);
			indices->push_back(1);
			indices->push_back(2);

			indices->push_back(2);
			indices->push_back(3);
			indices->push_back(0);

			vector<glm::vec2>* uv = new vector<glm::vec2>();
			uv->push_back(glm::vec2(0.0f, 0.0f));
			uv->push_back(glm::vec2(1.0f, 0.0f));
			uv->push_back(glm::vec2(1.0f, 1.0f));
			uv->push_back(glm::vec2(0.0f, 1.0f));

			return new Mesh(verts, indices, uv);
		}
	};
}