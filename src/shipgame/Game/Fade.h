#pragma once
#include "../Engine.h"
#include <functional>

namespace Navecita
{
	class Fade : GAME_BEHAVIOUR
	{
	public:
		DECLARE_BEHAVIOUR(Fade)

		void FadeIn();
		void FadeOut();
		void Update() override;

		void OnFadeIn(std::function<void()> callback);
		void OnFadeOut(std::function<void()> callback);
	private:
		enum class FadeType {
			In, Out
		};
		FadeType _fadeType;

		float _fadeValue = 1;
		float _speed = 0.04f;
		
		bool _fadeOutCallbacksCalled = false;
		bool _fadeInCallbacksCalled = true;

		vector<std::function<void()>> _fadeInCallback;
		vector<std::function<void()>> _fadeOutCallback;
	};

}

