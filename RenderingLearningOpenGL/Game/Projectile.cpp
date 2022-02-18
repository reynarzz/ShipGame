#include "Projectile.h"
#include "../GameHelper.h"
#include "Enemy.h"

namespace Navecita {

	Projectile::Projectile(GameEntity* entity) : EntityBehaviour(entity) {

	}

	void Projectile::SetTarget(const std::string& target)
	{
		_target = target;
	}

	void Projectile::Update() {

		auto pos = getGameEntity()->getTransform()->getPosition();
		glm::vec2 posOut(pos.x, pos.y);

		posOut += _moveDir * _speed;
		getGameEntity()->getTransform()->SetPosition(posOut.x, posOut.y, 0.0f);
	}

	void Projectile::OnRenderStart()
	{
		Texture* tex = new Texture();

		getGameEntity()->_renderer->_material->SetTexture(tex);
		tex->LoadImage("B:/Projects/UnityEditorGame/assets/navecita/Players.png");
		//tex->LoadImage("assets/spaceShooter/SpaceShooterAssetPack_Ships.png");

		auto atlas = SpriteAtlast(tex, 16);

		_anim = new SpriteAnimation(getGameEntity()->_renderer->_mesh);
		_anim->AddAnimUvLocation(atlas.getTileUV(0, 2));
		_anim->AddAnimUvLocation(atlas.getTileUV(1, 2));
		_anim->AddAnimUvLocation(atlas.getTileUV(2, 2));

		_anim->GoToFrame(1);
		tex->UnBind();
	}

	void Projectile::Shoot(glm::vec2 startPos, glm::vec2 dir, float speed)
	{
		_moveDir = dir;
		_speed = speed;

		getGameEntity()->getTransform()->SetPosition(startPos.x, startPos.y, 0);
	}

	void Projectile::OnCollision(GameEntity* entity)
	{
		if (entity->getName() == _target) {
			DestroyEntity(entity);
			DestroyEntity(getGameEntity());
		}
	}
}