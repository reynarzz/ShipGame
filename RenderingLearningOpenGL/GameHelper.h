#pragma once

#ifndef GAMEHELPER
#define GAMEHELPER


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
extern glm::mat4 _projM_;
extern glm::mat4 _viewM_;
extern ivec2 _screenSize_;
extern unsigned char* _currentFrameBufferTex_;

inline GameEntity* CreateGameEntity(std::string name) {

	GameEntity* entity = new GameEntity(name);

	Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	auto shaderPair = ShadersHelper::GetBasicShader();
	Material* material = new Material(new Shader(shaderPair.first, shaderPair.second));

	QuadRenderer* renderer = new QuadRenderer(material, quad);
	entity->_renderer = renderer;

	_scene->AddEntity(entity);

	return entity;
}

template<class T>
inline T* CreateComponent(GameEntity* gameEntity) {
	return new T(gameEntity);
}

template<class T>
inline T* CreateGameEntity(std::string name) {

	GameEntity* entity = CreateGameEntity(name);

	//GameEntity* entity = new GameEntity(name);

	//Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	//auto shaderPair = ShadersHelper::GetBasicShader();
	//Material* material = new Material(new Shader(shaderPair.first, shaderPair.second));

	//QuadRenderer* renderer = new QuadRenderer(material, quad);
	//entity->_renderer = renderer;

	Component* component = CreateComponent<T>(entity);
	entity->AddComponent(component);
	
	//_scene->AddEntity(entity);

	component->OnRenderStart();

	return (T*)component;
}



inline void DestroyEntity(GameEntity* entity) {
	_scene->DestroyEntity(entity);
}
#endif