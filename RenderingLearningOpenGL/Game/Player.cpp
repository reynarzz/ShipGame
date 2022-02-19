#include "Player.h"
#include "../GameHelper.h"
#include "Projectile.h"
#include <iostream>
#include "../PixelHelper.h"

namespace Navecita {

	Player::Player(GameEntity* entity) : EntityBehaviour(entity) {

	}

	Texture* _tar;
	PixelHelper _helper;
	vec2 _pos;
	void Player::Update() {

		float speed = 0.2f;
		_anim->Update();
		_angle += 0.1f;

		if (_input->_A_Pressed) {
			//_anim->GoToFrame(0);
			_pos.x -= speed;
		}
		else if (_input->_D_Pressed) {
			//_anim->GoToFrame(2);
			_pos.x += speed;
		}
		else {
			//_anim->GoToFrame(1);
		}

		if (_input->_S_Pressed) {
			_pos.y -= speed;
		}
		else if (_input->_W_Pressed) {
			_pos.y += speed;
		}

		if (_input->_shoot_Pressed) {
			_sootTime -= 0.0018;


			if (_sootTime <= 0) {

				Shoot();

				_sootTime = _shootInterval;
			}
		}
		else {
			_sootTime = 0.005f;
		}

		getGameEntity()->getTransform()->SetPosition(_pos.x, _pos.y, 0);

		_helper.RemovePixel(_tar, { 1.0f, 1.99f });
	}

	void Player::OnCollision(GameEntity* entity) {

		if (entity->getName() == "Enemy") {
			DestroyEntity(entity);
		}
	}

	void Player::OnRenderStart()
	{
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Players.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 16);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(1, 3));

		_anim->GoToFrame(0);

		tex->UnBind();

		Texture* tex2 = new Texture();
		tex2->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/white.png", Engine::Texture::ClampingMode::Clamp);

		auto destroyable = CreateGameEntity("Destroyable");
		destroyable->getTransform()->SetScale(8, 8, 8);
		destroyable->getTransform()->SetPosition(0, 10, 0);
		destroyable->_renderer->_material->SetTexture(tex2);

		tex2->UnBind();
		_tar = tex2;
	}

	void Player::SetInput_Test(KeyboardInput* input)
	{
		_input = input;
	}
	void Player::Shoot()
	{
		auto bullet = CreateGameEntity<Projectile>("PlayerBullet");
		bullet->SetTarget("Enemy");
		bullet->Shoot(_pos, { 0, 1 }, 0.5f);
	}
}