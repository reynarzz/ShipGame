#pragma once
#include "QuadRenderer.h"
#include "Camera.h"
#include "Entity.h"
#include <vector>
#include "AABB.h"
#include <typeinfo>

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
		const std::string& getName() const;
		void Update();
		AABB* GetAABB() const;
		 
		template<class T>
		T* getComponent() const {
				/*for (auto component : _components)
				{
					if (std::is_same<T, typeid(component)>::value) {
						return (T*)component;
					}

					if (decltype(component) a = T()) {

					}
				}*/
				return nullptr;
		}

		bool _pendingToDestroy;
	private:
		Transform* _transform;
		vector<Component*> _components;
		AABB* _aabb;
	};
}