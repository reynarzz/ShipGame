#include "EntityBehaviour.h"

namespace Engine {
    EntityBehaviour::EntityBehaviour(GameEntity* gameEntity) : _gameEntity(gameEntity)
    {
    }

    /*void EntityBehaviour::Start()
    {
    }

    void EntityBehaviour::Update()
    {
    }

    void EntityBehaviour::FixedUpdate()
    {
    }*/

    void EntityBehaviour::OnDestroyed()
    {
    }

    GameEntity* EntityBehaviour::getGameEntity()
    {
        return _gameEntity;
    }
}
