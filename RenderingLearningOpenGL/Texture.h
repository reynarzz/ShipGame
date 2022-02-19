#pragma once
#include <string>

namespace Engine {
	class Texture
	{
	public:
		enum class ClampingMode
		{
			Clamp,
			Repeat
		};

		Texture();
		~Texture();

		void LoadImage(const std::string&, ClampingMode clampingMode = ClampingMode::Clamp);
		void Bind(unsigned int slot = 0) const;
		void UnBind() const;

		unsigned int getTexID() const;
		int getWidth() const;
		int getHeight() const;
		void UpdateTexture(void* colors);
		unsigned char* _imageBuffer;
		int _channels;
		unsigned char col[2500*4];
	private:
		unsigned int _texID;
		int _width;
		int _height;
	};
}


