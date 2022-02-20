#pragma once

#ifndef GAMEHELPER
#define GAMEHELPER

#include "EntityBehaviour.h"
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

extern glm::mat4 _projMInv_;
extern glm::mat4 _viewMInv_;

extern ivec2 _screenSize_;
extern unsigned char* _currentFrameBufferTex_;
extern vector<unsigned int> _boundingBoxIndices_;
extern Camera* _camera_;

inline int gcd(int a, int b)
{
	while (b != 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
		{
			return a;
		}
	}
}

inline vec2 World2Pixel(vec2 pos) {
	auto ndc = _projM_* _viewM_ * glm::vec4(pos, 0., 1.0f);

	ndc = (ndc += 1) * 0.5f;

	return vec2(ndc.x * _screenSize_.x, ndc.y * _screenSize_.y);
}

inline Camera* GetCamera() {
	return _camera_;
}

inline glm::dvec3 Pixel2World(glm::ivec3 pixel) {

	double px = (double)pixel.x / (double)_screenSize_.x;
	double py = (double)pixel.y / (double)_screenSize_.y;

	auto ndc = (glm::dvec2(px, py) * 2.0);

	ndc -= 1.0f;

	auto resilt = _projMInv_ * _viewMInv_ * glm::vec4(ndc.x, ndc.y, 0.0, 1.0);

	return glm::dvec3(resilt.x, resilt.y, resilt.z);
}

inline vec2 Pixel2World(glm::ivec2 pixel) {
	return Pixel2World({ pixel.x, pixel.y, 0.f });
}

enum class ShaderType
{
	Basic,
	OutputXyCoord
};

inline GameEntity* CreateGameEntity(std::string name, int texWidth = 1, int texHeight = 1) {

	GameEntity* entity = new GameEntity(name);

	float factor = 1;
	float ppu = 1;

	
		 factor = gcd(texWidth, texHeight);
	pair<std::string, std::string> shaderPair;

	/*switch (shaderType)
	{
	case ShaderType::Basic:
		shaderPair = ShadersHelper::GetBasicShader();
		break;
	case ShaderType::OutputXyCoord:
		shaderPair = ShadersHelper::GetOutputPixelCoords();
		break;
	
	}*/
	shaderPair = ShadersHelper::GetBasicShader();

	Mesh* quad = Utils::GetQuadMesh((float)texWidth / factor * (texWidth / 16) , (float)texHeight / factor * (texHeight/  16));

	
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
inline T* CreateGameEntity(std::string name, int texWidth = 1, int texHeight = 1) {

	GameEntity* entity = CreateGameEntity(name, texWidth, texHeight);

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

template<typename T>
inline T* CreateEmptyGameEntity(const std::string name) {
	GameEntity* entity = new GameEntity(name);
	Component* component = CreateComponent<T>(entity);

	entity->AddComponent(component);

	component->OnRenderStart();

	_scene->AddEntity(entity);
	return (T*)component;
}


inline void DestroyEntity(GameEntity* entity) {
	_scene->DestroyEntity(entity);
}
#endif