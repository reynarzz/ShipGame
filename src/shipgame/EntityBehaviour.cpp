#include "EntityBehaviour.h"

namespace Engine {
    EntityBehaviour::EntityBehaviour(GameEntity* gameEntity) : _gameEntity(gameEntity)
    {
    }

    void EntityBehaviour::Update()
    {
    }

    void EntityBehaviour::OnRenderStart()
    {
    }

    Transform* EntityBehaviour::GetTransform() const
    {
        return _gameEntity->getTransform();
    }

    GameEntity* EntityBehaviour::getGameEntity()
    {
        return _gameEntity;
    }

    void EntityBehaviour::OnCollision(GameEntity* entity) { }
}
