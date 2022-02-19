#include "Background.h"
#include "../SpriteAtlast.h";

namespace Navecita {
	Background::Background(GameEntity* entity) : EntityBehaviour(entity)
	{

	}

	void Background::Update() {

		_scroll.y += 0.017f;

		_mat->SetScroll(_scroll);
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
