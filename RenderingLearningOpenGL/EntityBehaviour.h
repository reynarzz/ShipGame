#include "Component.h"

#pragma once

namespace Engine {
	class EntityBehaviour : Component
	{
		virtual void Start() = 0;
		virtual void Update() = 0;
		virtual void FixedUpdate() = 0;
		virtual void OnDestroyed() = 0;
	};
}