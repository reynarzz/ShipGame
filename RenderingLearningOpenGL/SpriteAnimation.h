#pragma once
#include <vector>
#include <glm/glm.hpp>
#include "Mesh.h"

using std::vector;
using glm::vec2;

namespace Engine {
	class SpriteAnimation
	{
	public:
		SpriteAnimation(Mesh* mesh);
		~SpriteAnimation();
		void Play();
		void Pause();
		void Stop();
		void Update();
		void SetFPS(const float& speed);
		int getFramesCount() const;
		void GoToFrame(int frame);
		void SetAnimUvLocation(vector<vec2> loc);
	private:
		vector<vector<vec2>>* _uvAnim;
		int _currentFrame;
		float _fps;
		bool _canPlay;
		Mesh* _mesh;
	};
}

