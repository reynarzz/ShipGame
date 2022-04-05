#include "Scene.h"
#include "GameHelper.h"
#include <iostream>

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
			_renderBoundingBox = false;
			if (!current->_pendingToDestroy && current->_renderer != nullptr) {
				current->Bind(_camera);
				//remove this from here
				glDrawElements(GL_TRIANGLES, current->_renderer->_mesh->getIndices().size(), GL_UNSIGNED_INT, NULL);

				if (_renderBoundingBox) {
					glDisable(GL_BLEND);
					glLineWidth(2);

					glBufferData(GL_ELEMENT_ARRAY_BUFFER, _boundingBoxIndices_.size() * sizeof(unsigned int), &_boundingBoxIndices_.at(0), GL_DYNAMIC_DRAW);

					glDrawElements(GL_LINES, _boundingBoxIndices_.size(), GL_UNSIGNED_INT, NULL);
					glEnable(GL_BLEND);

				}

				//Unbind
				current->UnBind();
			}
		}

		int pendingCount = _prendingEntities.size();

		for (auto i = 0; i < pendingCount; i++)
		{
			RemoveEntity(_prendingEntities.at(i));
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
	
		delete entity;
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