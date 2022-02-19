#include "Texture.h"
#include <glew.h>
#include "stb_image.h"

Engine::Texture::Texture() : _texID(0), _imageBuffer(NULL), 
						     _width(0), _height(0), _channels(0)
{
}

Engine::Texture::~Texture()
{
	glDeleteTextures(1, &_texID);
	stbi_image_free(_imageBuffer);
}

void Engine::Texture::LoadImage(const std::string& path, ClampingMode clampingMode)
{
	if (_texID != 0) {
		glDeleteTextures(1, &_texID);
	}

	stbi_set_flip_vertically_on_load(1);

	_imageBuffer = stbi_load(path.c_str(), &_width, &_height, &_channels, 4);
	
	glGenTextures(1, &_texID);
	glBindTexture(GL_TEXTURE_2D, _texID);

	int wrapMode = 0;
	switch (clampingMode)
	{
	case Engine::Texture::ClampingMode::Clamp:
		wrapMode = GL_CLAMP_TO_EDGE;
		break;
	case Engine::Texture::ClampingMode::Repeat:
		wrapMode = GL_REPEAT;
		break;
	}

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, wrapMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, wrapMode);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _imageBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	/*if (_imageBuffer)
		stbi_image_free(_imageBuffer);*/
}

void Engine::Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _texID);
}

void Engine::Texture::UnBind() const
{
	glActiveTexture(GL_TEXTURE0);

	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Engine::Texture::getTexID() const
{
	return _texID;
}

int Engine::Texture::getWidth() const
{
	return _width;
}

int Engine::Texture::getHeight() const
{
	return _height;
}

void Engine::Texture::UpdateTexture(void* colors)
{
	Bind();
	glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, _width, _height, GL_RGBA, GL_UNSIGNED_BYTE, colors);
	UnBind();
}