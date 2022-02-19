#pragma once
#include "Texture.h"
#include <glm/glm.hpp>
#include "Utils.h"

using namespace Engine;

using glm::ivec2;

class PixelHelper {
public:
	GLubyte rasters[24] = {
0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
0xff, 0x00, 0xff, 0x00, 0xc0, 0x00, 0xc0, 0x00, 0xc0, 0x00,
0xff, 0xc0, 0xff, 0xc0 };

	void RemovePixel(Texture* tex, vec2 coord) {

		int channels = 4;

		{
			
			int index = (round(coord.x * tex->getWidth()) * channels - 1) +
				round(tex->getWidth() * channels * round(tex->getWidth() * coord.y)  );

			tex->_imageBuffer[index - 3] = 0x00; // Red
			tex->_imageBuffer[index - 2] = 0xff; // Green
			tex->_imageBuffer[index - 1] = 0x00; // Blue
			tex->_imageBuffer[index] = 0xff;	 // Alpha
		}

		tex->UpdateTexture(tex->_imageBuffer);
	}

	static	ivec2 Texel2Screen(ivec2 coord) {

	}

	static	ivec2 Screen2Texel(ivec2 coord) {

	}

	static	vec2 World2Texel(int texWidth, int textHeight, glm::vec2 texPos, glm::vec2 target) {

		//Construct bounding box.
		float right = (texPos.x + texWidth * 0.5f);
		float left = (texPos.x - texWidth * 0.5f);
		float top = (texPos.y + textHeight * 0.5f);
		float bottom = (texPos.y - textHeight * 0.5f);

		float targetLeft = (target.x - 0.5f);
		float targetRight = (target.x + 0.5f);
		float targetTop = (target.y + 0.5f);
		float targetBottom = (target.y - 0.5f);

		//Normalize.
		if (((right <= targetRight && right >= targetLeft) || (left <= targetRight && left >= targetLeft)) &&
			((top <= targetTop && top >= targetBottom) || (bottom <= targetTop && bottom >= targetBottom)))
		{
			float yCoord = Utils::Normalize(target.y, top, bottom);
			float xCoord = Utils::Normalize(target.x, right, left);

			return vec2(xCoord, yCoord);
		}

		return { };
	}
};