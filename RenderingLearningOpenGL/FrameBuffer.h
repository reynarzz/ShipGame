#pragma once
class FrameBuffer
{
public:
	FrameBuffer(int width, int height);
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
	int _width;
	int _height;

};

