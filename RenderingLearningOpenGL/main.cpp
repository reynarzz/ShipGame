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
#include "Game/Player.h"
#include "SpriteAnimation.h"
#include "SpriteAtlast.h"
#include "Input.h"



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


KeyboardInput* _input;

using namespace Engine;
int gcd(int a, int b)
{
	while (b != 0)
	{
		int tmp = a;
		a = b;
		b = tmp % b;
		{
			return a;
		}
	}
}
//Mesh* GetQuadMesh2(float x = 1.0f, float y = 1.0f) {
//
//	vector<vec3>* verts = new vector<vec3>();
//	verts->push_back(vec3(-1.0f * x, -1.0f * y, 0.0));
//	verts->push_back(vec3(1.0 * x, -1.0 * y, 0.0));
//	verts->push_back(vec3(1.0 * x, 1.0 * y, 0.0));
//	verts->push_back(vec3(-1.0 * x, 1.0 * y, 0.0));
//
//	vector<unsigned int>* indices = new vector<unsigned int>();
//	indices->push_back(0);
//	indices->push_back(1);
//	indices->push_back(2);
//
//	indices->push_back(2);
//	indices->push_back(3);
//	indices->push_back(0);
//
//	vector<vec2>* uv = new vector<vec2>();
//	uv->push_back(vec2(0.0f, 0.0f));
//	uv->push_back(vec2(1.0f, 0.0f));
//	uv->push_back(vec2(1.0f, 1.0f));
//	uv->push_back(vec2(0.0f, 1.0f));
//
//	return new Mesh(verts, indices, uv);
//}

int main() {

	if (!glfwInit()) {

		std::cout << "can't init glfw";

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(420, 680, "Navecita", NULL, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "can't init glew";
		return -1;
	}

	_input = new KeyboardInput();

	GameEntity* gameEntity = new GameEntity("Nave");

	Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	Material* mat = new Material(new Shader(vertex, fragment));

	QuadRenderer* renderer = new QuadRenderer(mat, quad);
	gameEntity->_renderer = renderer;
	auto player = new Navecita::Player(gameEntity);
	player->SetInput_Test(_input);
	gameEntity->AddComponent(player);


	GameEntity* gameEntity2 = new GameEntity("Crater");
	Mesh* quad2 = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);


	Material* mat2 = new Material(new Shader(vertex, fragment));

	Texture* tex2 = new Texture();

	//mat2->SetTexture();
	QuadRenderer* renderer2 = new QuadRenderer(mat2, quad2);
	gameEntity2->_renderer = renderer2;


	Camera* cam = new Camera();
	cam->_viewTransform->SetPosition(0, -10, -10);

	Scene* scene = new Scene(nullptr);
	scene->SetCamera(cam);
	scene->AddEntity(gameEntity);
	scene->AddEntity(gameEntity2);

	int width, height;

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		_input->_A_Pressed = glfwGetKey(window, GLFW_KEY_A);
		_input->_D_Pressed = glfwGetKey(window, GLFW_KEY_D);
		_input->_S_Pressed = glfwGetKey(window, GLFW_KEY_S);
		_input->_W_Pressed = glfwGetKey(window, GLFW_KEY_W);
			
		glEnable(GL_BLEND);
		glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

		glClearColor(0.2f, 0.2f, 0.2f, 1.f);

		glfwGetWindowSize(window, &width, &height);

		float targetH = 16.0f*2;
		float targetW = 9.0f/2;// 9.0f;

		float scale_w = width / targetW;
		float scale_h = height / targetH;
		float w, h;

		if (scale_w < scale_h)
			w = targetW, h = height / scale_w;
		else
			h = targetH, w = width / scale_h;

		glViewport(0, 0, width, height);

		cam->SetOrtho(-w / 2, w / 2, -h / 2, h / 2);

		scene->Update();
		
		//glDrawElements(GL_TRIANGLES, quad->getIndices()->size(), GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}