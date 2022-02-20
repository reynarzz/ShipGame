#include "EntityBehaviour.h"

namespace Engine {
    EntityBehaviour::EntityBehaviour(GameEntity* gameEntity) : _gameEntity(gameEntity)
    {
    }

    Transform* EntityBehaviour::GetTransform() const
    {
        return _gameEntity->getTransform();
    }

    void EntityBehaviour::OnDestroyed()
    {
    }

    GameEntity* EntityBehaviour::getGameEntity()
    {
        return _gameEntity;
    }
}
