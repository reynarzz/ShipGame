#include "Shader.h"
#include <glew.h>
#include <iostream>

namespace Engine {

	Shader::Shader(std::string& vertexShaderStr, std::string& fragmentShaderStr) {
		LoadShader(vertexShaderStr, fragmentShaderStr);
	}

	void Shader::LoadShader(std::string& vertexShaderStr, std::string& fragmentShaderStr) {

		_programID = glCreateProgram();

		unsigned int v = Compile(vertexShaderStr, GL_VERTEX_SHADER);
		unsigned int f = Compile(fragmentShaderStr, GL_FRAGMENT_SHADER);

		glAttachShader(_programID, v);
		glAttachShader(_programID, f);
		glLinkProgram(_programID);

		glDeleteShader(v);
		glDeleteShader(f);
	}

	Shader::~Shader()
	{
		glDeleteProgram(_programID);
	}

	unsigned int Shader::Compile(std::string& shader, int shaderType) {

		unsigned int shaderID = glCreateShader(shaderType);

		const char* st = shader.c_str();
		glShaderSource(shaderID, 1, &st, NULL);
		glCompileShader(shaderID);

		int  success;
		char infoLog[512];
		glGetShaderiv(shaderID, GL_COMPILE_STATUS, &success);

		if (!success)
		{
			glGetShaderInfoLog(shaderID, 512, NULL, infoLog);
			std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog << std::endl;
		}

		return shaderID;
	}

	const unsigned int Shader::getProgram() const
	{
		return _programID;
	}

	const unsigned int Shader::Bind() const {

		glUseProgram(_programID);

		return _programID;
	}

	void Shader::Unbind() const
	{
		glUseProgram(0);
	}
}