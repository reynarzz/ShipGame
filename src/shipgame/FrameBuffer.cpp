#include "FrameBuffer.h"
#include <glew.h>
#include <iostream>

namespace Engine {
	FrameBuffer::FrameBuffer(int width, int height)
	{
		_width = width;
		_height = height;
		glGenTextures(1, &_texID);
		glBindTexture(GL_TEXTURE_2D, _texID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glGenFramebuffers(1, &_frameID);
		glBindFramebuffer(GL_FRAMEBUFFER, _frameID);

		
		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texID, 0);


		glGenRenderbuffers(1, &_renderBuffID);
		glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffID);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _renderBuffID);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}

	FrameBuffer::FrameBuffer(int width, int height, unsigned char* colors)
	{
		_width = width;
		_height = height;
		glGenTextures(1, &_texID);
		glBindTexture(GL_TEXTURE_2D, _texID);

		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA8, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, colors);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST);

		glGenFramebuffers(1, &_frameID);
		glBindFramebuffer(GL_FRAMEBUFFER, _frameID);


		glFramebufferTexture2D(GL_FRAMEBUFFER, GL_COLOR_ATTACHMENT0, GL_TEXTURE_2D, _texID, 0);


		glGenRenderbuffers(1, &_renderBuffID);
		glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffID);
		glRenderbufferStorage(GL_RENDERBUFFER, GL_DEPTH24_STENCIL8, width, height);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);

		glFramebufferRenderbuffer(GL_FRAMEBUFFER, GL_DEPTH_STENCIL_ATTACHMENT, GL_RENDERBUFFER, _renderBuffID);

		if (glCheckFramebufferStatus(GL_FRAMEBUFFER) != GL_FRAMEBUFFER_COMPLETE)
			std::cout << "ERROR::FRAMEBUFFER:: Framebuffer is not complete!" << std::endl;

		glBindFramebuffer(GL_FRAMEBUFFER, 0);
	}


	FrameBuffer::~FrameBuffer()
	{

	}

	void FrameBuffer::UpdateBuffer(int width, int height)
	{
	/*	_width = width;
		_height = height;
		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0,width, height, GL_RGBA, GL_UNSIGNED_BYTE, nullptr);*/
	}

	void FrameBuffer::Bind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, _frameID);
		glBindRenderbuffer(GL_RENDERBUFFER, _renderBuffID);
		//glBindTexture(GL_TEXTURE_2D, _texID);
	}

	void FrameBuffer::Unbind()
	{
		glBindFramebuffer(GL_FRAMEBUFFER, 0);
		glBindRenderbuffer(GL_RENDERBUFFER, 0);
		//glBindTexture(GL_TEXTURE_2D, 0);

	}

	int FrameBuffer::GetWidth() const
	{
		return _width;
	}

	int FrameBuffer::GetHeight() const
	{
		return _height;
	}

	unsigned int FrameBuffer::GetTexID() const
	{
		return _texID;
	}
}