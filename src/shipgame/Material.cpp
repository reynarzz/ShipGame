#include "Material.h"
#include <glew.h>
#include "GameHelper.h"
#include <iostream>

Engine::Material::Material(Shader* shader) : _shader(shader), 
_textures(std::vector<Texture*>()), _color(glm::vec4(1,1,1,1))
{
}

void Engine::Material::SetColor(glm::vec4 col)
{
	_color = col;
}

void Engine::Material::SetScroll(glm::vec2 scroll) {
	_scroll = scroll;
}

void Engine::Material::Bind() 
{
	_shader->Bind();

	SetIVec2("_SCREEN_", _screenSize_);
	SetVec4("_COLOR_", _color);
	SetVec2("_scroll", _scroll);
	//std::cout << _screenSize_.x << ", y: " << _screenSize_.y << "\n";
	for (unsigned int i = 0; i < _textures.size(); i++)
	{
		Texture* tex = _textures.at(i);
		
		std::string texName = "_tex" + std::to_string(i);
		
		tex->Bind(i);

		SetInt(texName, i);
	}

}

void Engine::Material::UnBind()
{
	_shader->Unbind();

	for (unsigned int i = 0; i < _textures.size(); i++)
	{
		Texture* tex = _textures.at(i);
		tex->UnBind();
	}
}

void Engine::Material::SetVec4(std::string name, glm::vec4 value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());
	glUniform4f(loc, value.x, value.y, value.z, value.w);
}

void Engine::Material::SetTexture(Texture* tex)
{
	_textures.push_back(tex);
}

void Engine::Material::SetVec3(std::string name, glm::vec3 value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());
	glUniform3f(loc, value.x, value.y, value.z);
}

void Engine::Material::SetVec2(std::string name, glm::vec2 value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());
	glUniform2f(loc, value.x, value.y);
}

void Engine::Material::SetIVec2(std::string name, glm::ivec2 value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());
	glUniform2i(loc, value.x, value.y);
}

void Engine::Material::SetInt(std::string name, int value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());

	glUniform1i(loc, 0);
}

void Engine::Material::SetMat4(std::string name, glm::mat4 value) const
{
	unsigned int loc = glGetUniformLocation(_shader->getProgram(), name.c_str());

	glUniformMatrix4fv(loc, 1, GL_FALSE, &value[0][0]);
}

Engine::Material::~Material()
{
	_textures.clear();

	delete _shader;
}