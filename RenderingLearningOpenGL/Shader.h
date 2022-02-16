#include <string>
#pragma once

namespace Engine {
	class Shader
	{
	public:
		Shader(std::string& vertexShaderStr, std::string& fragmentShaderStr);

		void LoadShader(std::string& vertexShaderStr, std::string& fragmentShaderStr);

		const unsigned int getProgram() const;
		const unsigned int Bind() const;
		void Unbind() const;

	private:
		unsigned int Compile(std::string& shaderStr, int shaderType);
		unsigned int _programID;
	};
}
