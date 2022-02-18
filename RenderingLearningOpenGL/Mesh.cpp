#include "Mesh.h"

namespace Engine {
	Mesh::Mesh(vector<vec3> verts, vector<unsigned int> indices, vector<glm::vec2> texcoord) :
		_indices(indices), _indexBuffer(0), _meshID(0), _vertexArrayID(0)
	{
		UnBind();

		_vertexData = vector<float>();

		/*int vBoBound;
		int vaoBound;

		glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &vBoBound);
		glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &vaoBound);*/

		for (size_t i = 0; i < verts.size(); i++)
		{
			glm::vec3 pos = verts.at(i);
			glm::vec2 uv = texcoord.at(i);

			_vertexData.push_back(pos.x);
			_vertexData.push_back(pos.y);
			_vertexData.push_back(pos.z);

			_vertexData.push_back(uv.x);
			_vertexData.push_back(uv.y);
		}


		glGenVertexArrays(1, &_vertexArrayID);
		glBindVertexArray(_vertexArrayID);

		// Set Vertices buffer
		glGenBuffers(1, &_meshID);
		glBindBuffer(GL_ARRAY_BUFFER, _meshID);

		glBufferData(GL_ARRAY_BUFFER, _vertexData.size() * sizeof(float) * 3, &_vertexData.at(0), GL_DYNAMIC_DRAW);

		// Vertices
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)0);

		// UV
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 5 * sizeof(float), (void*)(3 * sizeof(float)));

		// Set Index buffer
		glGenBuffers(1, &_indexBuffer);
		glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _indexBuffer);
		glBufferData(GL_ELEMENT_ARRAY_BUFFER, indices.size() * sizeof(unsigned int), &indices.at(0), GL_STATIC_DRAW);

		// Unbind vertex array buffer
		UnBind();
	}

	const vector<unsigned int> Mesh::getIndices() const {
		return _indices;
	}

	void Mesh::updateTexcoord(vector<glm::vec2>& texcoord)
	{
		Bind();

		auto it = _vertexData.begin();
		for (int i = 0; i < texcoord.size(); i++)
		{
			it += 3;

			*it = texcoord.at(i).x;
			it++;
			*it = texcoord.at(i).y;
			it++;
		}

		glBufferSubData(GL_ARRAY_BUFFER, 0, _vertexData.size() * sizeof(float) * 3, &_vertexData.at(0));
	}

	void Mesh::Bind() const {
		glBindVertexArray(_vertexArrayID);
		glBindBuffer(GL_ARRAY_BUFFER, _meshID);

		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);
	}

	void Mesh::UnBind() const
	{
		//glDisableVertexAttribArray(0);
		//glDisableVertexAttribArray(1);
		glBindBuffer(GL_ARRAY_BUFFER, 0);

		glBindVertexArray(0);
	}

	Mesh::~Mesh() {
		//	delete[] _indices;
	}

}