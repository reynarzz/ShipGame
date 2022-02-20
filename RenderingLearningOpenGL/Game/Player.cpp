#include "Player.h"
#include "../GameHelper.h"
#include "Projectile.h"
#include "Player.h"

namespace Navecita {
	Transform* _point;

	INIT_BEHAVIOUR(Player)

	void Player::Update() {

		_anim->Update();

		float speed = 0.2f;

		vec3 pos = GetTransform()->getPosition();

		if (Input::_A_Pressed) {
			//_anim->GoToFrame(0);
			pos.x -= speed;
		}
		else if (Input::_D_Pressed) {
			//_anim->GoToFrame(2);
			pos.x += speed;
		}
		else {
			//_anim->GoToFrame(1);
		}

		if (Input::_S_Pressed) {
			pos.y -= speed;
		}
		else if (Input::_W_Pressed) {
			pos.y += speed;
		}

		if (Input::_Space_Pressed) {
			_sootTime -= 0.0018;


			if (_sootTime <= 0) {

				Shoot();

				_sootTime = _shootInterval;
			}
		}
		else {
			_sootTime = 0.005f;
		}

		getGameEntity()->getTransform()->SetPosition(pos.x, pos.y, 0);

		//if (_input->_shoot_Pressed)
		{

			//	{
			//		
			//		auto projPos = vec2(_pos.x, _pos.y + 3);

			//		vec2 pixelPos = World2Pixel(projPos);
			//		vec2 newpos = Pixel2World(pixelPos);

			//		std::cout << "x: " << projPos.x << ", y: " << projPos.y << " | " << " x: " << newpos.x << ", y: " << newpos.y << "\n";
			//		for (size_t i = 0; i < 16; i++)
			//		{
			//			pixels[i] = NULL;
			//		}

			//		int maxChecks = _screenSize_.y *2;

			//		while (!pixels[0] && maxChecks > 0)
			//		{
			//			maxChecks--;

			//			glReadPixels(pixelPos.x, pixelPos.y, 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, &pixels);

			//			if (pixels[0]) {
			//				projPos = Pixel2World({ pixelPos.x, pixelPos.y, 0 });
			//			}

			//			// advance to the next pixel.
			//			pixelPos.y += 1.0f;
			//		}

			//		bool hit;
			//		auto coord = _helper.World2Texel(64 / 16, 64 / 16, Pixel2World(World2Pixel( { 0, 0 })), projPos, hit);
			//		

			//		{
			//			_helper.RemovePixel(_tar, coord);
			//		}
			//	}
		}
	}

	void Player::OnCollision(GameEntity* entity) {

		if (entity->getName() == "Enemy") {
			_life -= 1;

			if (_life <= 0) {
				DestroyEntity(getGameEntity());
			}
		}
	}

	void Player::OnRenderStart()
	{
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Players.png");

		SpriteAtlast atlas = SpriteAtlast(tex, 16);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(1, 3));

		_anim->GoToFrame(0);

		tex->UnBind();
	}

	void Player::Shoot()
	{
		auto bullet = CreateGameEntity<Projectile>("PlayerBullet", 16, 16);

		auto pos = GetTransform()->getPosition();
		bullet->SetTarget("Enemy");
		bullet->Shoot({ pos.x, pos.y + 1 }, { 0, 1 }, 0.6f);
	}

	void Player::SetDestroyableTex(Texture* tex)
	{
	}
}