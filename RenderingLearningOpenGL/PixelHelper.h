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

		
		int index = (round(coord.x * tex->getWidth()) * channels - 1) +
			round(tex->getWidth() * channels * round(tex->getWidth() * coord.y));

		tex->_imageBuffer[index - 3] = 0xff; // Red
		tex->_imageBuffer[index - 2] = 0x00; // Green
		tex->_imageBuffer[index - 1] = 0x00; // Blue
		tex->_imageBuffer[index] = 0xff;	 // Alpha

		tex->UpdateTexture(tex->_imageBuffer);
	}

	static	ivec2 Texel2Screen(ivec2 coord) {
		//Camera matrix
		//coord * _VP_ * screenWith * screenheigh
	}

	static	ivec2 Screen2Texel(ivec2 coord) {

	}

	static vec2 World2Texel(int texWidth, int textHeight, glm::vec2 texPos, glm::vec2 target, bool& hit) {

		//Construct bounding box.

		float targetHeight = 1;
		float targetWidth = 1;

		float texLeft = (texPos.x - texWidth );
		float texRight = (texPos.x + texWidth );
		float texTop = (texPos.y + textHeight );
		float texBottom = (texPos.y - textHeight);


		float left = (target.x - targetWidth / 2);
		float right = (target.x + targetWidth / 2);
		float top = (target.y + targetHeight / 2);
		float bottom = (target.y - targetHeight / 2);
		


		if (((right <= texRight && right >= texLeft) || (left <= texRight && left >= texLeft)) &&
			((top <= texTop && top >= texBottom) || (bottom <= texTop && bottom >= texBottom))) {
			float yCoord = Utils::Normalize(target.y, texTop, texBottom);
			float xCoord = Utils::Normalize(target.x, texRight, texLeft);
			hit = true;
			return vec2(abs(xCoord), abs(yCoord));
		}
		hit = false;
		return { 0.0, 0.0 };
	}
};