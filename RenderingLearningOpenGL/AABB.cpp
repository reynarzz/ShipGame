#include "AABB.h"

namespace Engine {
	AABB::AABB(float x, float y, float w, float h, bool solid) :
		_x(x), _y(y), _width(w), _height(h) {
	}

	/*AABB* box_new(float x, float y, float w, float h, int solid)
	{
		AABB* box = new AABB();

		box->x = (x) ? x : 0.0f;
		box->y = (y) ? y : 0.0f;
		box->width = (w) ? w : 1.0f;
		box->height = (h) ? h : 1.0f;

		return(box);
	}*/

	bool AABB::Collide(AABB* target)
	{
		/*return (
			_x > target->_x + target->_width &&
			_x + _width < target->_x&&
			_y > target->_y + target->_height &&
			_y + _height < target->_y
			);*/

		float left = (_x - _width / 2);
		float right = (_x + _width / 2);
		float top = (_y + _height / 2);
		float bottom = (_y - _height / 2);


		float targetLeft = (target->_x - target->_width / 2);
		float targetRight = (target->_x + target->_width / 2);
		float targetTop = (target->_y + target->_height / 2);
		float targetBottom = (target->_y - target->_height / 2);

		return ((right < targetRight && right > targetLeft) || (left < targetRight && left > targetLeft)) &&
		       ((top < targetTop && top > targetBottom) || (bottom < targetTop && bottom > targetBottom));
	}

	void AABB::UpdateBoundingBox(float x, float y, float w, float h)
	{
		_x = x;
		_y = y;
		_width = w;
		_height = h;
	}
}
