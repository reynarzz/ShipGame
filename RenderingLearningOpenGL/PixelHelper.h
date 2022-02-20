#pragma once
#include "Texture.h"
#include <glm/glm.hpp>
#include "Utils.h"

using namespace Engine;

using glm::ivec2;

class PixelHelper {
public:
	void RemovePixel(Texture* tex, vec2 coord) {

		int channels = 4;
		//

		int index = (round(coord.x * tex->getWidth()) * channels - 1) +
			round(tex->getWidth() * channels * round(tex->getWidth() * coord.y));

		tex->_imageBuffer[index - 3] = 0x00; // Red
		tex->_imageBuffer[index - 2] = 0x00; // Green
		tex->_imageBuffer[index - 1] = 0x00; // Blue
		tex->_imageBuffer[index] = 0x00;	 // Alpha

		tex->UpdateTexture(tex->_imageBuffer);
	}

	void RemovePixel(Texture* tex, int xPixel, int yPixel) {

		int channels = 4;
		// mesh position
		// devuelve la cordenada de cada pixel usando un shader.
		int index = xPixel;

		for (size_t i = 0; i < tex->getWidth() * tex->getHeight() * channels; i++)
		{
			auto a = GetNormalizedPixelCoords(i, tex->getWidth(), tex->getHeight());
			//std::cout << "x: " << a.x << ", y: "<< a.y << "\n";	 // Alpha

			if ((int)a.x == xPixel && (int)a.y == yPixel) {
				tex->_imageBuffer[i - 3] = 0xff; // Red
				tex->_imageBuffer[i - 2] = 0x00; // Green
				tex->_imageBuffer[i - 1] = 0x00; // Blue
				tex->_imageBuffer[i] = 0x00;	 // Alpha

				//std::cout << "found: " << tex->_imageBuffer[i] << "\n";	 // Alpha


			}
			//if (tex->_imageBuffer[i] != 0 && tex->_imageBuffer[i] < tex->getHeight()) {
			//	std::cout << "found: " << tex->_imageBuffer[i] << "\n";	 // Alpha

			//}
		}

		//tex->_imageBuffer[index - 3] = 0x00; // Red
		//tex->_imageBuffer[index - 2] = 0x00; // Green
		//tex->_imageBuffer[index - 1] = 0x00; // Blue
		//tex->_imageBuffer[index] = 0x00;	 // Alpha

		tex->UpdateTexture(tex->_imageBuffer);
	}

	struct Point2D { float x; float y; };

	Point2D GetNormalizedPixelCoords(int pixelIdx, int imageWidth, int imageHeight) {
		Point2D point;
		point.x = round(pixelIdx % imageWidth) - imageWidth; // (float)(imageWidth - 1);
		point.y = round(pixelIdx / imageWidth) - imageHeight;  // (float)(imageHeight - 1);
		return point;
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

		float texLeft = (texPos.x - texWidth);
		float texRight = (texPos.x + texWidth);
		float texTop = (texPos.y + textHeight);
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