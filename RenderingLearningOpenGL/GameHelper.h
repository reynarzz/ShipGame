
#pragma once

//
//class GameHelper
//{
//public:
#ifndef GameHelper
#define GameHelper


#include "Mesh.h"
#include "Material.h"
#include "QuadRenderer.h"
#include "Game/Player.h"
#include "Utils.h"
#include "ShadersHelper.h"
#include "Scene.h"
#include "GameEntity.h"

#include <string>
extern Scene* _scene;

template<class T>
inline T* CreateComponent(GameEntity* gameEntity) {
	return new T(gameEntity);
}

template<class T>
inline T* CreateGameEntity(std::string name) {

	GameEntity* entity = new GameEntity(name);

	Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	auto shaderPair = ShadersHelper::GetBasicShader();
	Material* material = new Material(new Shader(shaderPair.first, shaderPair.second));

	QuadRenderer* renderer = new QuadRenderer(material, quad);
	entity->_renderer = renderer;
	Component* component = CreateComponent<T>(entity);
	entity->AddComponent(component);

	_scene->AddEntity(entity);

	return (T*)component;
}


#endif	
//private:
//
//};