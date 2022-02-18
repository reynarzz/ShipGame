#pragma once
#include "Component.h"

#include "Material.h"
#include "Mesh.h"

namespace Engine {

	class QuadRenderer : public Component
	{
	public:
		QuadRenderer(Material* mat, Mesh* mesh);
		~QuadRenderer();

		Material* _material;
		Mesh* _mesh;

		void Bind(glm::mat4 modelM, glm::mat4 viewM, glm::mat4 projM) const;
		void UnBind() const;

		virtual void Update() override;
		virtual void OnRenderStart() override;
	};
}


