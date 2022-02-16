#pragma once
#include "Camera.h"
#include <vector>

namespace Engine {
	class GameEntity
	{
	public:
		void Bind(Camera*);
		QuadRenderer* _renderer;
		
	private:
		//--vector<Component*> _components;
	};
}