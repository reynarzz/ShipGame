#pragma once
#include "GameEntity.h"
#include "EntityBehaviour.h"

using namespace Engine;

#define INIT_BEHAVIOUR(className) className::className(GameEntity* entity) : EntityBehaviour(entity) { }
#define DECLARE_BEHAVIOUR(className) className(GameEntity* entity);\
~className();\
void Update() override;\
void OnRenderStart() override;\
