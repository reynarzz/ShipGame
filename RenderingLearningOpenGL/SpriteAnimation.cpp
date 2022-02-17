#include "SpriteAnimation.h"

namespace Engine {
	SpriteAnimation::SpriteAnimation(Mesh* mesh) : _mesh(mesh), _canPlay(false), _currentFrame(0),
												   _fps(0.1f), _uvAnim(new vector<vector<vec2>>())
	{
	}

	SpriteAnimation::~SpriteAnimation()
	{
		delete[] _uvAnim;
	}

	void SpriteAnimation::Update()
	{
		if (_canPlay && _uvAnim->size() > 0) {
			_time += _fps;

			_currentFrame = glm::trunc(((sin(_time) + 1.0f) * 0.5f) * _uvAnim->size());

			if (_currentFrame >= _uvAnim->size()) {
				_time = 0;
				_currentFrame = 0;
			}

			_mesh->updateTexcoord(_uvAnim->at(_currentFrame));
		}
	}

	void SpriteAnimation::Play()
	{
		_canPlay = true;
	}

	void SpriteAnimation::Pause()
	{
		_canPlay = false;
	}

	void SpriteAnimation::Stop()
	{
		_canPlay = false;
		_currentFrame = 0;
		_time = 0;
	}

	void SpriteAnimation::SetFPS(const float& speed)
	{
		_fps = speed;
	}

	int SpriteAnimation::getFramesCount() const
	{
		return _uvAnim->size();
	}

	void SpriteAnimation::GoToFrame(int frame)
	{
		_currentFrame = frame;
		_mesh->updateTexcoord(_uvAnim->at(_currentFrame));
	}

	void SpriteAnimation::AddAnimUvLocation(vector<vec2> loc)
	{
		_uvAnim->push_back(loc);
		_mesh->updateTexcoord(_uvAnim->at(0));
	}
}
