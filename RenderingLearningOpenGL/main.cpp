#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include "Entity.h"
#include "Mesh.h"
#include "Utils.h"


std::string vertex = "#version 330 core\n"
"layout (location=0) in vec3 vPos;\n"
"layout (location=1) in vec2 _texCoord;\n"
"out vec2 _texUV;\n"
"void main(){\n"
"gl_Position = vec4(vPos.x, vPos.y, vPos.z, 1.0);\n"
"_texUV = _texCoord;\n"
"}\n";

std::string fragment = "#version 330 core\n"
"out vec4 col;\n"
"in vec2 _texUV;\n"
"uniform sampler2D _tex0;\n"
"void main(){\n"
"col = texture2D(_tex0, _texUV) * vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\n";


int main() {

	if (!glfwInit()) {

		std::cout << "can't init glfw";

		return -1;
	}
	
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	
	GLFWwindow* window = glfwCreateWindow(500, 500, "Reynardo's renderer", NULL, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "can't init glew";
		return -1;
	}

	Engine::Mesh* quad = Engine::Utils::GetQuadMesh(0.2f);

	Engine::Texture* tex = new Engine::Texture();
	tex->LoadImage("C:/Users/Reynardo/Desktop/shipTest.png");

	Engine::Material* mat = new Engine::Material(new Engine::Shader(vertex, fragment));
	mat->SetTexture(tex);

	Engine::QuadRenderer* renderer = new Engine::QuadRenderer(mat, quad);
	
	renderer->Bind(glm::mat4(1.0f), glm::mat4(1.0f), glm::mat4(1.0f));

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glClearColor(0.2f, 0.2f, 0.2f, 1.f);
		int width, height;
		glfwGetWindowSize(window, &width, &height);

		glViewport(0, 0, width, height);

		glDrawElements(GL_TRIANGLES, quad->getIndices()->size(), GL_UNSIGNED_INT, NULL);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}