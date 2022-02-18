#include "Entity.h"
#include "GameEntity.h"
#include <iostream>

namespace Engine {

	GameEntity::GameEntity(std::string name) : Entity(name), _renderer(nullptr)
	{
		_aabb = new AABB(0, 0, 1, 1);
		std::cout << "Entity:" << name << "\n";

		_transform = new Transform();
	}

	void GameEntity::Update()
	{
		glm::vec3 pos = _transform->getPosition();

		_aabb->UpdateBoundingBox(pos.x, pos.y, 1, 1);

		for (Component* component : _components)
		{
			component->Update();
		}
	}

	AABB* GameEntity::GetAABB() const
	{
		return _aabb;
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

	const std::string& GameEntity::getName() const
	{
		return _name;
	}

	void GameEntity::Bind(Camera* cam)
	{
		_renderer->Bind(_transform->getModelM(), cam->getView(), cam->getProj());
	}

	void GameEntity::UnBind()
	{
		_renderer->UnBind();
	}

	Transform* GameEntity::getTransform() const
	{
		return _transform;
	}

	GameEntity::~GameEntity()
	{
		delete _transform;
		delete _renderer;
		delete _aabb;

		_components.clear();
	}
}
