#pragma once
#include <map>

#include "GameEntity.h"
#include "EntityBehaviour.h"
#include "QuadRenderer.h"
#include "Camera.h"
#include "Renderer.h"
#include <functional>
#include <utility>

using std::map;

namespace Engine {
	class Scene
	{
	public:
		Scene(Renderer* renderer);
		~Scene();

		void AddEntity(GameEntity* entity);
		void DestroyEntity(GameEntity* entity);
		
		void Start();
		void Update();
		void SetCamera(Camera* camera);
	private:
		void RemoveEntity(GameEntity* entity);

		map<int, QuadRenderer>* _renderers = nullptr;
		map<int, vector<EntityBehaviour*>>* _behaviours = nullptr;
		vector<GameEntity*> _entities;
		vector<GameEntity*> _prendingEntities;
		Camera* _camera;
	};
}