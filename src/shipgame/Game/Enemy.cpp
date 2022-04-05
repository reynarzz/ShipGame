#include "Enemy.h"
#include "../GameEntity.h"
#include "Player.h"
#include "../Gamehelper.h"
#include "../Time.h"

namespace Navecita {

	Enemy::Enemy(GameEntity* entity) : EntityBehaviour(entity) {
		entity->GetAABB()->_width = 2;
		entity->GetAABB()->_height = 2;
	}

	void Enemy::OnRenderStart() {
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("assets/navecita/Players.png");

		auto atlas = SpriteAtlast(tex, 16);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);

		int val = rand() % 3;

		_anim->AddAnimUvLocation(atlas.getTileUV(val, 0));

		_anim->GoToFrame(0);
		getGameEntity()->getTransform()->SetPosition(0, 10, 0);
		//_anim->Play();
		tex->UnBind();
	}

	vec2 _enemyPos;
	void Enemy::Update() {

		_anim->Update();

		auto pos = getGameEntity()->getTransform()->getPosition();


		getGameEntity()->getTransform()->SetPosition(pos.x, pos.y - 5 * Time::DeltaTime, 0);
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
		else if (entity->getName() == "PlayerBullet") {
			_life -= 1;

			if (_life <= 0) {
				DestroyEntity(getGameEntity());
			}
		}
	}
}