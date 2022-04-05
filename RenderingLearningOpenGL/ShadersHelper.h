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

	static std::pair<std::string, std::string> GetScreenQuad() {
		std::string vertex = "#version 330 core\n"
			"layout (location=0) in vec3 vPos;\n"
			"layout (location=1) in vec2 _texCoord;\n"
			"uniform mat4 _MVP_;"
			"out vec2 _texUV;\n"
			"void main(){\n"
			"gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);\n"
			"_texUV = _texCoord;\n"
			"}\n";

		std::string fragment = "#version 330 core\n"
			"out vec4 col;\n"
			"in vec2 _texUV;\n"
			"uniform sampler2D _tex0;\n"
			"uniform ivec2 _SCREEN_;\n"
			"uniform vec4 _COLOR_;\n"
			"uniform ivec2 _MOUSE_;\n"
			"void main(){\n"
			"float r = texture2D(_tex0, _texUV + vec2(1.0f / 288.0f, 1.0f / 512.0f)).r; \n"
			"float g = texture2D(_tex0, _texUV + vec2(-1.0f / 288.0f, -1.0f / 512.0f)).g; \n"
			"float b = texture2D(_tex0, _texUV + vec2(-1.0f / 288.0f, 1.0f / 512.0f)).b; \n"
			"vec4 c = texture2D(_tex0, _texUV); \n"
			"col =vec4(c.r, g, b, 1.0);\n"
			"}\n";

		return std::pair<std::string, std::string>(vertex, fragment);
	}

	static std::pair<std::string, std::string> GetOutputPixelCoords() {
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
			"uniform ivec2 _MOUSE_;\n"
			"void main(){\n"
			//"if(distance(vec2(x,y), vec2(_MOUSE_.x, _MOUSE_.y)) < round(256.0f * 0.01f))\n"
			
			"vec4 tex = texture2D(_tex0, _texUV);\n"
			"int x = int(round(gl_FragCoord.x));\n"
			"int y = int(round(gl_FragCoord.y));\n"
			"tex.y = x;\n"
			"tex.z = y;\n"
			"col = tex;\n"
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

