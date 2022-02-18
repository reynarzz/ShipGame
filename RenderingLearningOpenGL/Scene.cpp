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

			for (size_t j = 0; j < count; j++)
			{
				auto target = _entities.at(j);

				if (!ge->_pendingToDestroy && !target->_pendingToDestroy && ge != target) {
					if (ge->GetAABB()->Collide(target->GetAABB())) {
						((EntityBehaviour*)ge->getComponents().at(0))->OnCollision(target);
						((EntityBehaviour*)target->getComponents().at(0))->OnCollision(ge);
					
					}
				}
				else {
					continue;
				}
			}

			ge->Bind(_camera);

			//remove this from here
			glDrawElements(GL_TRIANGLES, ge->_renderer->_mesh->getIndices().size(), GL_UNSIGNED_INT, NULL);

			//Unbind
			ge->UnBind();
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