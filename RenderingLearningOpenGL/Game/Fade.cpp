#include "Fade.h"
#include <iostream>

namespace Navecita
{
	INIT_BEHAVIOUR(Fade) { }

	void Fade::FadeIn()
	{
		_fadeType = FadeType::In;
	}

	void Fade::FadeOut()
	{
		_fadeType = FadeType::Out;
	}

	void Fade::Update()
	{
		switch (_fadeType)
		{
		case Fade::FadeType::In:
			_fadeValue = glm::clamp(_fadeValue + _speed, 0.0f, 1.00001f);
		
			if (_fadeValue >= 1.0f && !_fadeInCallbacksCalled)
			{
				_fadeOutCallbacksCalled = false;

				_fadeInCallbacksCalled = true;

				for (size_t i = 0; i < _fadeInCallback.size(); i++)
				{
					_fadeInCallback.at(i)();
				}
			}
			break;
		case Fade::FadeType::Out:
			_fadeValue = glm::clamp(_fadeValue - _speed, -0.0001f, 1.0f);

			if (_fadeValue <= 0.0f && !_fadeOutCallbacksCalled)
			{
				_fadeInCallbacksCalled = false;

				_fadeOutCallbacksCalled = true;

				for (size_t i = 0; i < _fadeOutCallback.size(); i++)
				{
					_fadeOutCallback.at(i)();
				}
			}

			break;
		}

		getGameEntity()->_renderer->_material->SetColor({ 0.1f, 0.1f, 0.1f, _fadeValue });
		//std::cout << _fadeValue << "\n";
	}

	void Fade::OnFadeIn(std::function<void()> callback)
	{
		_fadeInCallback.push_back(callback);

	}

	void Fade::OnFadeOut(std::function<void()> callback)
	{
		_fadeOutCallback.push_back(callback);
	}
}