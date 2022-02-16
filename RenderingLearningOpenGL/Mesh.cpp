#include "Mesh.h"

namespace Engine {
	Mesh::Mesh(vector<vec3>* verts, vector<unsigned int>* indices, vector<glm::vec2>* texcoord) :
		_vertices(verts), _indices(indices)
	{
		vector<float> vertAttrib;

		for (size_t i = 0; i < verts->size(); i++)
		{
			glm::vec3 pos = verts->at(i);
			glm::vec2 uv = texcoord->at(i);

			vertAttrib.push_back(pos.x);
			vertAttrib.push_back(pos.y);
			vertAttrib.push_back(pos.z);

			vertAttrib.push_back(uv.x);
			vertAttrib.push_back(uv.y);
		}

		glGenVertexArrays(1, &_vertexArrayID);
		glBindVertexArray(_vertexArrayID);

		// Set Vertices buffer
		glGenBuffers(1, &_meshID);
		glBindBuffer(GL_ARRAY_BUFFER, _meshID);


		glBufferData(GL_ARRAY_BUFFER, vertAttrib.size() * sizeof(float) * 3, &vertAttrib.at(0), GL_STATIC_DRAW);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

		// UV
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));
		glEnableVertexAttribArray(1);

		// Set Index buffer
		unsigned int elementID;
		glGenBuffers(1, &elementID);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, elementID);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices->size() * sizeof(unsigned int), &indices->at(0), GL_STATIC_DRAW);

		// Unbind vertex array buffer
		glBindVertexArray(0);
	}

	const vector<vec3>* Mesh::getVertices() const {
		return _vertices;
	}

	const vector<unsigned int>* Mesh::getIndices() const {
		return _indices;
	}

	void Mesh::Bind() const {
		glBindVertexArray(_vertexArrayID);
		glEnableVertexAttribArray(0);
	}

	Mesh::~Mesh() {
		delete[] _vertices;
		delete[] _indices;
	}

}