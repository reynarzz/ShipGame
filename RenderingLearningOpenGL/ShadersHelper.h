#pragma once
#include <string>
class ShadersHelper
{
public:
	static std::pair<std::string, std::string> GetBasicShader() {
		std::string vertex = "#version 330 core\n"
			"layout (location=0) in vec3 vPos;\n"
			"layout (location=1) in vec2 _texCoord;\n"
			"uniform mat4 _MVP_;"
			"out vec2 _texUV;\n"
			"void main(){\n"
			"gl_Position = _MVP_ * vec4(vPos.x, vPos.y, vPos.z, 1.0);\n"
			"_texUV = _texCoord;\n"
			"}\n";



		std::string fragment = "#version 330 core\n"
			"out vec4 col;\n"
			"in vec2 _texUV;\n"
			"uniform sampler2D _tex0;\n"
			"uniform vec4 _COLOR_;\n"
			"uniform vec2 _scroll;\n" 
			"void main(){\n"
			"col = texture2D(_tex0, _texUV + _scroll) * _COLOR_;\n"
			"}\n";

		return std::pair<std::string, std::string>(vertex, fragment);
	}

	//static std::pair<std::string, std::string> GetBackgroundShader() {
	//	std::string vertex = "#version 330 core\n"
	//		"layout (location=0) in vec3 vPos;\n"
	//		"layout (location=1) in vec2 _texCoord;\n"
	//		"out vec2 _texUV;\n"
	//		"void main(){\n"
	//		"gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);\n"
	//		"_texUV = _texCoord;\n"
	//		"}\n";


	//	std::string fragment = "#version 330 core\n"
	//		"out vec4 col;\n"
	//		"in vec2 _texUV;\n"
	//		"uniform sampler2D _tex0;\n"
	//		"uniform vec4 _COLOR_;\n"
	//		"uniform vec2 _scroll;" 
	//		"void main(){\n"
	//		"col = texture2D(_tex0, _texUV + _scroll) * _COLOR_;\n"
	//		"}\n";

	//	return std::pair<std::string, std::string>(vertex, fragment);
	//}
};

