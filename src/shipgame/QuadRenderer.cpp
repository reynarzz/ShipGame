#include "QuadRenderer.h"

Engine::QuadRenderer::QuadRenderer(Material* mat, Mesh* mesh) : _material(mat), _mesh(mesh)
{
}

void Engine::QuadRenderer::Bind(glm::mat4 modelM, glm::mat4 viewM, glm::mat4 projM) const
{
	if (_mesh != nullptr) {
		_mesh->Bind();
	}

	if (_material != nullptr) {
		_material->Bind();
		_material->SetMat4("_MODEL_", modelM);
		_material->SetMat4("_VIEW_", viewM);
		_material->SetMat4("_PROJ_", projM);
		_material->SetMat4("_MVP_", projM * viewM * modelM);
	}
}

void Engine::QuadRenderer::UnBind() const
{
	_mesh->UnBind();
	_material->UnBind();
}

void Engine::QuadRenderer::Update()
{
}

void Engine::QuadRenderer::OnRenderStart() {

}

Engine::QuadRenderer::~QuadRenderer()
{
	delete _mesh;
	delete _material;
}
