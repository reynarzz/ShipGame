#include "Player.h"

namespace Navecita {

	Player::Player(GameEntity* entity) : EntityBehaviour(entity) {
		_anim = new SpriteAnimation(entity->_renderer->_mesh);
		Texture* tex = new Texture();
		entity->_renderer->_material->SetTexture(tex);
		tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");
		
		auto atlas = SpriteAtlast(tex, 8);
		_anim->AddAnimUvLocation(atlas.getTileUV(0.0, 8.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(1.0, 8.0));
		_anim->AddAnimUvLocation(atlas.getTileUV(2.0, 8.0));

		_anim->GoToFrame(1);

	}

	void Player::Start()
	{

	}
	vec2 _pos;
	void Player::Update() {

		_anim->Update();
		_angle += 0.1f;
		if (_input->_A_Pressed) {
			_anim->GoToFrame(0);
			_pos.x -= 0.1f;
		}
		else if (_input->_D_Pressed) {
			_anim->GoToFrame(2);
			_pos.x += 0.1f;
		}
		else {
			_anim->GoToFrame(1);
		}

		if (_input->_S_Pressed) {
			_pos.y -= 0.1f;
		}
		else if (_input->_W_Pressed) {
			_pos.y += 0.1f;

		}

		getGameEntity()->getTransform()->SetPosition(_pos.x, _pos.y, 0);

		//getGameEntity()->getTransform()->SetPosition(0, sin(_angle), 0);
		//getGameEntity()->getTransform()->SetRotation(0, 0, _angle * 0.5f);
		//getGameEntity()->getTransform()->SetScale(4, 4, 4);
	}

	void Player::FixedUpdate()
	{

	}
	void Player::SetInput_Test(KeyboardInput* input)
	{
		_input = input;
	}
}