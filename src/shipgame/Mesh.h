#pragma once

#include <glew.h>
#include <glm/glm.hpp>
#include <vector>

using std::vector;
using glm::vec3;

namespace Engine {

	class BoundingBox {
		vector<glm::vec2> horizontal;
		vector<glm::vec2> vertical;
	};

	class Mesh
	{
	public:
		Mesh(vector<vec3> verts, vector<unsigned int> indices, vector<glm::vec2> texcoord);
		~Mesh();
		
		void Bind() const;
		void UnBind() const;

		const vector<vec3>* getVertices() const;
		const vector<unsigned int> getIndices() const;

		void updateTexcoord(vector<glm::vec2>& texcoord);

	private:
		unsigned int _meshID;
		unsigned int _indexBuffer;
		unsigned int _vertexArrayID;
		vector<unsigned int> _indices;
		vector<float> _vertexData;
	};
}