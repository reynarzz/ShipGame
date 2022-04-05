#pragma once
#include "Texture.h"
namespace Engine {
	class FrameBuffer
	{
	public:
		FrameBuffer(int width, int height);
		FrameBuffer(int width, int height, unsigned char* colors);
		~FrameBuffer();

		void UpdateBuffer(int width, int height);
		void Bind();
		void Unbind();
		int GetWidth() const;
		int GetHeight() const;

		unsigned int GetTexID() const;
	private:
		unsigned int _frameID;
		unsigned int _texID;
		unsigned int _renderBuffID;
		int _width;
		int _height;
	};
}


