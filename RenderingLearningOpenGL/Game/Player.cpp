#include "Player.h"
#include "../GameHelper.h"
#include "Projectile.h"

namespace Navecita {

	Player::Player(GameEntity* entity) : EntityBehaviour(entity) {
		Texture* tex = new Texture();
		_aabb = new AABB();

		entity->_renderer->_material->SetTexture(tex);
		tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");
		
		auto atlas = SpriteAtlast(tex, 8);

		_anim = new SpriteAnimation(entity->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(0.0, 5.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(1.0, 5.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(2.0, 5.0));

		_anim->GoToFrame(1);

		tex->UnBind();
	}

	void Player::Start()
	{

	}
	vec2 _pos;
	void Player::Update() {

		_anim->Update();
		_angle += 0.1f;
		float speed = 0.2f;
		if (_input->_A_Pressed) {
			_anim->GoToFrame(0);
			_pos.x -= speed;
		}
		else if (_input->_D_Pressed) {
			_anim->GoToFrame(2);
			_pos.x += speed;
		}
		else {
			_anim->GoToFrame(1);
		}

		if (_input->_S_Pressed) {
			_pos.y -= speed;
		}
		else if (_input->_W_Pressed) {
			_pos.y += speed;

		}
		

		getGameEntity()->getTransform()->SetPosition(_pos.x, _pos.y, 0);

		if (_input->_shoot_Pressed) {
			auto bullet = CreateGameEntity<Projectile>("PlayerBullet");

			//bullet->Shoot(_pos, { 0, 1 }, 0.1f);
		}

		_aabb->UpdateBoundingBox(_pos.x, _pos.y, 1, 1);
	}

	void Player::FixedUpdate()
	{

	}
	void Player::SetInput_Test(KeyboardInput* input)
	{
		_input = input;
	}
}