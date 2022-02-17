#pragma once
#include <string>

namespace Engine {
	class Texture
	{
	public:
		Texture();
		~Texture();

		void LoadImage(const std::string&);
		void Bind(unsigned int slot = 0) const;
		void UnBind() const;

		unsigned int getTexID() const;
		int getWidth() const;
		int getHeight() const;

	private:
		unsigned int _texID;
		int _width;
		int _height;
		unsigned char* _imageBuffer;
		int _channels;
	};
}


