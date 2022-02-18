#include "Enemy.h"

namespace Navecita {

	Enemy::Enemy(GameEntity* entity) : EntityBehaviour(entity) {
		_aabb = new AABB();
		Texture* tex = new Texture();

		entity->_renderer->_material->SetTexture(tex);
		tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 8);

		_anim = new SpriteAnimation(entity->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(0.0, 6.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(1.0, 6.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(2.0, 6.0));

		_anim->GoToFrame(1);
		getGameEntity()->getTransform()->SetPosition(0, 10, 0);
		_anim->Play();
		tex->UnBind();
	}

	void Enemy::Start()
	{

	}
	vec2 _enemyPos;
	void Enemy::Update() {

		_anim->Update();

		auto pos = getGameEntity()->getTransform()->getPosition();
		_aabb->UpdateBoundingBox(pos.x, pos.y, 2, 2);

		/*_angle += 0.1f;
		float speed = 0.2f;
		if (_input->_A_Pressed) {
			_anim->GoToFrame(0);
			_enemyPos.x -= speed;
		}
		else if (_input->_D_Pressed) {
			_anim->GoToFrame(2);
			_enemyPos.x += speed;
		}
		else {
			_anim->GoToFrame(1);
		}

		if (_input->_S_Pressed) {
			_enemyPos.y -= speed;
		}
		else if (_input->_W_Pressed) {
			_enemyPos.y += speed;

		}
		*/
	}

	void Enemy::FixedUpdate()
	{

	}
	void Enemy::SetInput_Test(KeyboardInput* input)
	{
		_input = input;
	}
}