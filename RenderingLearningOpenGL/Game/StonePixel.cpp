#pragma once
#include "StonePixel.h"

namespace Navecita {

	StonePixel::StonePixel(GameEntity* entity) : EntityBehaviour(entity) {

	}

	void StonePixel::SetTarget(const std::string& target)
	{
		_target = target;
	}

	void StonePixel::Update() {

		auto pos = getGameEntity()->getTransform()->getPosition();
		glm::vec2 posOut(pos.x, pos.y);

		posOut += _moveDir * _speed;
		getGameEntity()->getTransform()->SetPosition(posOut.x, posOut.y, 0.0f);
	}

	void StonePixel::OnRenderStart()
	{
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Players.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 16);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);

		_anim->AddAnimUvLocation(atlas.getTileUV(2, 1));


		_anim->AddAnimUvLocation(atlas.getTileUV(0, 2));
		_anim->AddAnimUvLocation(atlas.getTileUV(1, 2));
		_anim->AddAnimUvLocation(atlas.getTileUV(2, 2));
		_anim->AddAnimUvLocation(atlas.getTileUV(3, 2));

		_anim->GoToFrame(0);
		tex->UnBind();
	}

	void StonePixel::Shoot(glm::vec2 startPos, glm::vec2 dir, float speed)
	{
		_moveDir = dir;
		_speed = speed;

		getGameEntity()->getTransform()->SetPosition(startPos.x, startPos.y, 0);
	}

	void StonePixel::OnCollision(GameEntity* entity)
	{
		if (entity->getName() == _target) {
			//DestroyEntity(entity);

			////destroy StonePixel.
			//DestroyEntity(getGameEntity());

			//CreateGameEntity<Navecita::Enemy>("Enemy")->GetTransform()->SetPosition({ -4, 13, 0 });
		}
	}
}