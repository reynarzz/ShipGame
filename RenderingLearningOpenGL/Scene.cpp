#include "Scene.h"

namespace Engine {

	Scene::Scene(Renderer* renderer) : _camera(nullptr) {

	}
	
	void Scene::Start()
	{
		
	}

	void Scene::Update()
	{
		int count = _entities.size();

		for (int i = 0; i < count; i++)
		{
			GameEntity* ge = _entities.at(i);

			ge->Update();

			ge->Bind(_camera);

			//remove this from here
			glDrawElements(GL_TRIANGLES, ge->_renderer->_mesh->getIndices().size(), GL_UNSIGNED_INT, NULL);

			//Unbind
			ge->UnBind();
		}
	}

	void Scene::FixedUpdate()
	{ 

	}

	void Scene::SetCamera(Camera* camera)
	{
		_camera = camera;
	}

	void Scene::AddEntity(GameEntity* entity)
	{
		_entities.push_back(entity);
	}

	void Scene::RemoveEntity(GameEntity* entity)
	{
		int count = _entities.size();
		vector<GameEntity*>::iterator it = _entities.begin();
		
		for (; it < _entities.end(); it++)
		{
			if (*it == entity) {
				_entities.erase(it);
				break;
			}
		}
	}

	void Scene::DestroyEntity(GameEntity* entity)
	{
		RemoveEntity(entity);

		delete entity;
	}

	Scene::~Scene()
	{
		delete _camera;
	}
}