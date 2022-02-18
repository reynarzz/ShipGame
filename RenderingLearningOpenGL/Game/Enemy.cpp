#include "Enemy.h"

namespace Navecita {

	Enemy::Enemy(GameEntity* entity) : EntityBehaviour(entity) {
		_aabb = new AABB();
		
	}

	void Enemy::Start()
	{

	}

	vec2 _enemyPos;
	void Enemy::Update() {

		_anim->Update();

		auto pos = getGameEntity()->getTransform()->getPosition();
		_aabb->UpdateBoundingBox(pos.x, pos.y, 2, 2);
	}

	void Enemy::OnRenderStart() {
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 8);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(0.0, 6.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(1.0, 6.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(2.0, 6.0));

		_anim->GoToFrame(1);
		getGameEntity()->getTransform()->SetPosition(0, 10, 0);
		_anim->Play();
		tex->UnBind();
	}
}