#include "Player.h"
#include "../GameHelper.h"
#include "Projectile.h"
#include <iostream>
#include "../PixelHelper.h"

namespace Navecita {
	Transform* _point;

	Player::Player(GameEntity* entity) : EntityBehaviour(entity) {
		auto test = CreateGameEntity<Navecita::Projectile>("test", 16, 16);
		test->GetTransform()->SetPosition({ 0, -8, 0 });
		test->getGameEntity()->_renderer->_material->SetColor({ 1, 0,0,1 });
		_point = test->GetTransform();
	}
	unsigned char* pixels[16] = { nullptr };
	unsigned char* prevPixels[16] = { nullptr };

	Texture* _tar;
	PixelHelper _helper;
	vec3 _pos;
	float _destroy = 5;
	vector<GameEntity*> _projectiles;
	vector<ivec2> _destroyed;
	void Player::Update() {

		float speed = 0.1f;
		//_anim->Update();
		_angle += 0.1f;
		_pos = GetTransform()->getPosition();
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

		if (_destroy < 0) {
			_destroy = 5;

			float valx = (rand() % 100) / 100.0f;
			float valy = (rand() % 100) / 100.0f;

			//	_helper.RemovePixel(_tar, { valx, valy });
		}

		//for (auto it = _projectiles.begin(); it < _projectiles.end(); it++)
		if(_input->_shoot_Pressed)
		{
			
			//Safe destroy
			//while (true)
			{
				//auto NDC = _projM_ * _viewM_ * glm::vec4(projPos, 1.0f);

				//// to 0 - +1 range instead of -1 - +1
				//NDC = (NDC += 1) * 0.5f;

				//int xPixel = round(NDC.x * _screenSize_.x);
				//int yPixel = round(NDC.y * _screenSize_.y);
				auto projPos = vec2(_pos.x, _pos.y + 3);//(*it)->getTransform()->getPosition();

				vec2 pixelPos = World2Pixel(projPos);
				vec2 newpos = Pixel2World(pixelPos);

				std::cout << "x: " << projPos.x << ", y: " << projPos.y << " | " << " x: " << newpos.x << ", y: " << newpos.y << "\n";
				for (size_t i = 0; i < 16; i++)
				{
					pixels[i] = NULL;
				}

				int maxChecks = _screenSize_.y *2;

				while (!pixels[0] && maxChecks > 0)
				{
					maxChecks--;

					glReadPixels(pixelPos.x, pixelPos.y, 8, 8, GL_RGBA, GL_UNSIGNED_BYTE, &pixels);

					if (pixels[0]) {
						projPos = Pixel2World({ pixelPos.x, pixelPos.y, 0 });
					}

					// advance to the next pixel.
					pixelPos.y += 1.0f;
				}

				bool hit;
				auto coord = _helper.World2Texel(64 / 16, 64 / 16, Pixel2World(World2Pixel( { 0, 0 })), projPos, hit);
				//_point->SetPosition({ projPos, 0.0f });
				//ivec2 iCoord = ivec2((int)round(coord.x * _tar->getWidth()), (int)round(coord.y * _tar->getHeight()));

				//auto it2 = std::find(_destroyed.begin(), _destroyed.end(), iCoord);


				//if (coord.x != 0 && coord.y != 0 && it2 == _destroyed.end() && pixels[0])
				{
					//_destroyed.push_back(iCoord);
					//_helper.RemovePixel(_tar, pixelPos.x, pixelPos.y);
					_helper.RemovePixel(_tar, coord);
					//DestroyEntity(*it);

					//_projectiles.erase(it);
					//break;
				}
			}
		}

		_destroy -= 0.4f;
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
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Player.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 16);

		//_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);
		//_anim->AddAnimUvLocation(atlas.getTileUV(1, 3));

		//_anim->GoToFrame(0);

		tex->UnBind();


	}

	void Player::SetInput_Test(KeyboardInput* input)
	{
		_input = input;
	}
	void Player::Shoot()
	{
		//auto bullet = CreateGameEntity<Projectile>("PlayerBullet");
		//bullet->SetTarget("Enemy");
		//bullet->Shoot({ _pos.x, _pos.y + 1.2f }, { 0, 1 }, 0.2f);
		////_projectiles.push_back(bullet->getGameEntity());
	}

	void Player::SetDestroyableTex(Texture* tex)
	{
		_tar = tex;
	}
}