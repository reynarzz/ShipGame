#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include "Scene.h"
#include "Entity.h"
#include "Mesh.h"
#include "Utils.h"
#include "Camera.h"
#include "GameEntity.h"

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
"void main(){\n"
"col = texture2D(_tex0, _texUV) * vec4(1.0, 1.0, 1.0, 1.0);\n"
"}\n";

using namespace Engine;

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

	
	GameEntity* gameEntity = new GameEntity();

	Mesh* quad = Utils::GetQuadMesh(1.0f);

	Texture* tex = new Texture();
	tex->LoadImage("C:/Users/Reynardo/Desktop/shipTest.png");

	Material* mat = new Material(new Shader(vertex, fragment));

	mat->SetTexture(tex);

	QuadRenderer* renderer = new QuadRenderer(mat, quad);
	gameEntity->_renderer = renderer;

	Camera* cam = new Camera();
	cam->_viewTransform->SetPosition(0, 0, -10);

	Scene* scene = new Scene(nullptr);
	scene->SetCamera(cam);
	scene->AddEntity(gameEntity);

	int width, height;

	float angle = 0;
	
	float targetAspectRatio =  9.0f / 16.0f;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);


		glClearColor(0.2f, 0.2f, 0.2f, 1.f);
		
		glfwGetWindowSize(window, &width, &height);
		glViewport(0, 0, width, height);

		scene->Update();

		cam->SetProj(45.0f, (float)width / height, 1.0f, 100.0f);
		
		angle += 0.01f;

		gameEntity->getTransform()->SetPosition(0, sin(angle), 0);
		gameEntity->getTransform()->SetRotation(0, angle * 0.5f, 0);


		glDrawElements(GL_TRIANGLES, quad->getIndices()->size(), GL_UNSIGNED_INT, NULL);
		
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}