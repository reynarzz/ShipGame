#pragma once
#include "QuadRenderer.h"
#include "Camera.h"
#include "Entity.h"
#include <vector>

namespace Engine {
	class GameEntity : Entity
	{
	public:
		GameEntity(std::string name = "EntityObj");
		~GameEntity();

		void Bind(Camera*);
		void UnBind();
		QuadRenderer* _renderer;
		Transform* getTransform() const;

		void AddComponent(Component* component);
		void RemoveComponent(Component* component);
		vector<Component*> getComponents();

		void Update();

	private:
		Transform* _transform;
		vector<Component*> _components;
	};
}