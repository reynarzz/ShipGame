#include "Shader.h"
#include <glm/glm.hpp>
#include "Texture.h"
#include <vector>
#pragma once

namespace Engine {
	class Material
	{
	public:
		
		Material(Shader* shader);
		~Material();

		void Bind() const;
		void UnBind();
		void SetVec3(std::string name, glm::vec3 value) const;
		void SetInt(std::string name, int value) const;
		void SetMat4(std::string name, glm::mat4 value) const;
		void SetVec4(std::string name, glm::vec4 value) const;
		void SetTexture(Texture* tex);

	private:
		Shader* _shader;
		std::vector<Texture*> _textures;
	};
}
