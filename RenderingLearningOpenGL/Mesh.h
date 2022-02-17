#include <glew.h>
#include <glm/glm.hpp>
#include <vector>

using std::vector;
using glm::vec3;

#pragma once
namespace Engine {

	class Mesh
	{
	public:
		Mesh(vector<vec3>& verts, vector<unsigned int>* indices, vector<glm::vec2>& texcoord);
		~Mesh();
		
		void Bind() const;

		const vector<vec3>* getVertices() const;
		const vector<unsigned int>* getIndices() const;

	private:
		unsigned int _meshID;
		unsigned int _vertexArrayID;
		vector<unsigned int>* _indices;
	};
}


