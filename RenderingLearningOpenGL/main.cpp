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

void Set(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (action == GLFW_PRESS || action == GLFW_REPEAT) {
		if (key == GLFW_KEY_A) {
			_input->_A_Pressed = true;
			_input->_D_Pressed = false;

		}
		else if (key == GLFW_KEY_D) {
			_input->_D_Pressed = true;
			_input->_A_Pressed =false;

		}
		else {
			_input->_A_Pressed = false;
			_input->_D_Pressed = false;
		}

		if (key == GLFW_KEY_W) {
			_input->_W_Pressed = true;
			_input->_S_Pressed = false;

		}
		else if (key == GLFW_KEY_S) {
			_input->_S_Pressed = true;
			_input->_W_Pressed = false;

		}
		else {
			_input->_W_Pressed = false;
			_input->_S_Pressed = false;
		}
	}
	else {
		_input->_A_Pressed = false;
		_input->_D_Pressed = false;
		_input->_W_Pressed = false;
		_input->_S_Pressed = false;
	}
}

void Init(GLFWwindow* window) {

	_input = new KeyboardInput();
	/*bool aPressed = false;
	bool DPressed = false;
	glfwSetKeyCallback(window, Set);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, GLFW_TRUE);*/
}

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

int main() {

	if (!glfwInit()) {

		std::cout << "can't init glfw";

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	GLFWwindow* window = glfwCreateWindow(420, 680, "Navecita", NULL, nullptr);

	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK) {
		std::cout << "can't init glew";
		return -1;
	}

	Init(window);
	GameEntity* gameEntity = new GameEntity("Nave");
	//Texture* tex = new Texture();
	
	//tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png");
	
	//int texWidth = tex->getWidth();
	//int textHeight = tex->getHeight();


	//float factor = gcd(texWidth, textHeight);

	Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	float tileSize = 8.0f;

	//SpriteAnimation* anim = new SpriteAnimation(quad);

	//SpriteAtlast atlas(tex, tileSize);
	
//	anim->AddAnimUvLocation(atlas.getTileUV(0.0, 8.0));
	//anim->AddAnimUvLocation(atlas.getTileUV(1.0, 8.0));
	//anim->AddAnimUvLocation(atlas.getTileUV(2.0, 8.0));
	//anim->SetAnimUvLocation(atlas.getTileUVLoc(6.0, 5.0));


	Material* mat = new Material(new Shader(vertex, fragment));

//	mat->SetTexture(tex);

	QuadRenderer* renderer = new QuadRenderer(mat, quad);
	gameEntity->_renderer = renderer;
	auto player = new Navecita::Player(gameEntity);
	player->SetInput_Test(_input);
	gameEntity->AddComponent(player);

	Camera* cam = new Camera();
	cam->_viewTransform->SetPosition(0, 0, -10);

	Scene* scene = new Scene(nullptr);
	scene->SetCamera(cam);
	scene->AddEntity(gameEntity);

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

		float targetH = 16.0f;
		float targetW = 16.0f;// 9.0f;

		float scale_w = width / targetW;
		float scale_h = height / targetH;
		float w, h;

		if (scale_w < scale_h)
			w = targetW, h = height / scale_w;
		else
			h = targetH, w = width / scale_h;

		glViewport(0, 0, width, height);

		cam->SetOrtho(-w / 2, w / 2, -h / 2, h / 2);

	//	anim->Update();

		scene->Update();

		glDrawElements(GL_TRIANGLES, quad->getIndices()->size(), GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}