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
			GameEntity* current = _entities.at(i);

			current->Update();


			// Brute force collision verification.
			for (size_t j = 0; j < count; j++)
			{
				auto target = _entities.at(j);
				//if(target.Collidable())
				if (!current->_pendingToDestroy && !target->_pendingToDestroy && current != target) {
					if (current->GetAABB()->Collide(target->GetAABB())) {
						((EntityBehaviour*)current->getComponents().at(0))->OnCollision(target);
						((EntityBehaviour*)target->getComponents().at(0))->OnCollision(current);
					
					}
				}
				else {
					continue;
				}
			}

			current->Bind(_camera);

			//remove this from here
			glDrawElements(GL_TRIANGLES, current->_renderer->_mesh->getIndices().size(), GL_UNSIGNED_INT, NULL);

			//Unbind
			current->UnBind();
		}

		for (auto i = _prendingEntities.begin(); i != _prendingEntities.end(); i++)
		{
			RemoveEntity(*i);
		}

		_prendingEntities.clear();
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
		
		for (; it != _entities.end(); it++)
		{
			if (*it == entity) {
				_entities.erase(it);
				break;
			}
		}
	
		//delete entity;
	}

	void Scene::DestroyEntity(GameEntity* entity)
	{
		entity->_pendingToDestroy = true;
		_prendingEntities.push_back(entity);
	}

	Scene::~Scene()
	{
		delete _camera;
	}
}