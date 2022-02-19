#include "AABB.h"

namespace Engine {
	AABB::AABB(float x, float y, float w, float h, bool solid) :
		_x(x), _y(y), _width(w), _height(h) {
	}

	AABB::~AABB()
	{
	}

	bool AABB::Collide(AABB* target)
	{
		if (target != nullptr) {
			float left = (_x - _width / 2);
			float right = (_x + _width / 2);
			float top = (_y + _height / 2);
			float bottom = (_y - _height / 2);


			float targetLeft = (target->_x - target->_width / 2);
			float targetRight = (target->_x + target->_width / 2);
			float targetTop = (target->_y + target->_height / 2);
			float targetBottom = (target->_y - target->_height / 2);

			return ((right <= targetRight && right >= targetLeft) || (left <= targetRight && left >= targetLeft)) &&
			       ((top <= targetTop && top >= targetBottom) || (bottom <= targetTop && bottom >= targetBottom));
		}
	}

	void AABB::UpdateBoundingBox(float x, float y, float w, float h)
	{
		_x = x;
		_y = y;
		_width = w;
		_height = h;
	}
}
