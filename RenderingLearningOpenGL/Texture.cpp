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
}

void Engine::Texture::LoadImage(const std::string& path)
{
	stbi_set_flip_vertically_on_load(1);

	_imageBuffer = stbi_load(path.c_str(), &_width, &_height, &_channels, 4);

	glGenTextures(1, &_texID);
	glBindTexture(GL_TEXTURE_2D, _texID);

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);


	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, _imageBuffer);
	glBindTexture(GL_TEXTURE_2D, 0);

	if (_imageBuffer)
		stbi_image_free(_imageBuffer);
}

void Engine::Texture::Bind(unsigned int slot) const
{
	glActiveTexture(GL_TEXTURE0 + slot);
	glBindTexture(GL_TEXTURE_2D, _texID);
}

void Engine::Texture::UnBind() const
{
	glBindTexture(GL_TEXTURE_2D, 0);
}

unsigned int Engine::Texture::getTexID() const
{
	return _texID;
}
