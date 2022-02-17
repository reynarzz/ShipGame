#include "Entity.h"
#include "GameEntity.h"
#include <iostream>

namespace Engine {
	
	GameEntity::GameEntity(std::string name) : Entity(name), _renderer(nullptr)
	{
		std::cout << "Entity:"<< name << "\n";

		_transform = new Transform();
	}

	void GameEntity::Update()
	{
		for (Component* component : _components)
		{
			component->Update();
		}
	}

	void GameEntity::AddComponent(Component* component)
	{
		_components.push_back(component);
	}

	void Engine::GameEntity::RemoveComponent(Component* component)
	{
	}

	vector<Component*> GameEntity::getComponents()
	{
		return _components;
	}

	void GameEntity::Bind(Camera* cam)
	{
		_renderer->Bind(_transform->getModelM(), cam->getView(), cam->getProj());
	}

	Transform* GameEntity::getTransform() const
	{
		return _transform;
	}


	GameEntity::~GameEntity()
	{
		delete _transform;
		delete _renderer;
	}
}
