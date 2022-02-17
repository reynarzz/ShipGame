#include "SpriteAnimation.h"

namespace Engine {
	SpriteAnimation::SpriteAnimation(Mesh* mesh) : _mesh(mesh), _canPlay(false), _currentFrame(0), _fps(0.1f), _uvAnim(new vector<vector<vec2>>())
	{
	}

	SpriteAnimation::~SpriteAnimation()
	{
	}

	float _as;
	void SpriteAnimation::Update()
	{
		if (_uvAnim->size() > 0) {
			_as += _fps;

			int index = glm::round(_as);

			if (index >= _uvAnim->size()) {
				_as = 0;
				index = 0;
			}

			_mesh->updateTexcoord(_uvAnim->at(index));
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
	}

	void SpriteAnimation::SetAnimUvLocation(vector<vec2> loc)
	{
		_uvAnim->push_back(loc);
	}
}
