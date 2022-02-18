#include "Background.h"
#include "../SpriteAtlast.h";

namespace Navecita {
	Background::Background(GameEntity* entity) : EntityBehaviour(entity)
	{

	}
	glm::vec2 _sd;

	void Background::Update() {

		_sd.y += 0.02f;

		_mat->SetScroll(_sd);
	}

	void Background::OnCollision(GameEntity* entity)
	{

	}

	void Background::OnRenderStart() {
		Texture* tex = new Texture();
		_mat = getGameEntity()->_renderer->_material;

		_mat->SetTexture(tex);
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Background.png", Texture::ClampingMode::Repeat);
		_mat->SetColor({ 0.5f,0.5f ,0.5f , 1.0f });

		getGameEntity()->getTransform()->SetScale(10, 20, 10);
		getGameEntity()->getTransform()->SetPosition(0, 10, 0);

		tex->UnBind();
	}
}
