#pragma once
#include "GameEntity.h"
#include "EntityBehaviour.h"
#include "Input.h"

using namespace Engine;
#define GAME_BEHAVIOUR public EntityBehaviour

#define INIT_BEHAVIOUR(className) className::className(GameEntity* entity) : EntityBehaviour(entity) 
#define DECLARE_BEHAVIOUR(className) className(GameEntity* entity);\
~className();
