#include "Player.h"

namespace Navecita {

	Player::Player(GameEntity* entity) : EntityBehaviour(entity) {

	}

	void Player::Start()
	{

	}

	void Player::Update() {

		_angle += 0.1f;

		//getGameEntity()->getTransform()->SetPosition(0, sin(_angle), 0);
		//getGameEntity()->getTransform()->SetRotation(0, 0, _angle * 0.5f);
		getGameEntity()->getTransform()->SetScale(4, 4, 4);
	}

	void Player::FixedUpdate()
	{

	}
}