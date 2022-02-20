#pragma once
#include "Engine.h"

class Fade : public Engine::EntityBehaviour
{
public:
	DECLARE_BEHAVIOUR(Fade)

	void FadeIn();
	void FadeOut();
};

