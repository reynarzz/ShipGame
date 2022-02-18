#include "Enemy.h"
#include "../GameEntity.h"
#include "Player.h"
namespace Navecita {

	Enemy::Enemy(GameEntity* entity) : EntityBehaviour(entity) {
		entity->GetAABB()->_width = 2;
		entity->GetAABB()->_height = 2;
	}

	void Enemy::OnRenderStart() {
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 8);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);

		int val = rand() % 4;

		_anim->AddAnimUvLocation(atlas.getTileUV(0.0, 6.0 + val));
		_anim->AddAnimUvLocation(atlas.getTileUV(1.0, 6.0 + val));
		_anim->AddAnimUvLocation(atlas.getTileUV(2.0, 6.0 + val));

		_anim->GoToFrame(1);
		getGameEntity()->getTransform()->SetPosition(0, 10, 0);
		_anim->Play();
		tex->UnBind();
	}

	vec2 _enemyPos;
	void Enemy::Update() {

		_anim->Update();

		auto pos = getGameEntity()->getTransform()->getPosition();


		getGameEntity()->getTransform()->SetPosition(pos.x, pos.y - 0.1f, 0);
	}

	Enemy::~Enemy()
	{

	}

	void Enemy::OnCollision(GameEntity* entity)
	{
		if (entity->getName() == "Player") {
			//auto a = entity->getComponent<Enemy>();
			auto p = (Player*)entity->getComponents().at(0);
			//entity->_renderer->_material->SetColor({ 0, 0,1, 1 });
		}
	}
}