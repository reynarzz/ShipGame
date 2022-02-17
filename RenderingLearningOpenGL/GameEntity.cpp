#include "Entity.h"
#include "GameEntity.h"

namespace Engine {
	//void Engine::GameEntity::Bind(Camera*)
	//{
	//}

	GameEntity::GameEntity(std::string name) : Entity(name)
	{
		_transform = new Transform();
	}

	void GameEntity::Update()
	{

	}

	void Engine::GameEntity::AddComponent(Component* component)
	{
	}

	void Engine::GameEntity::RemoveComponent(Component* component)
	{
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
