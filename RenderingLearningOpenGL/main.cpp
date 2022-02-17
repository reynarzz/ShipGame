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


	GameEntity* gameEntity = new GameEntity("Nave");
	gameEntity->AddComponent(new Navecita::Player(gameEntity));
	Texture* tex = new Texture();
	int texWidth = 0;
	int textHeight = 0;

	tex->LoadImage("C:/Users/Reynardo/Desktop/spaceShooter/SpaceShooterAssetPack_Ships.png", texWidth, textHeight);


	float factor = gcd(texWidth, textHeight);

	Mesh* quad = Utils::GetQuadMesh(/*(float)texWidth / factor, (float)textHeight / factor*/);

	float texAspectWidth = texWidth; (float)texWidth / factor;
	float texAspectHeigh = textHeight; (float)textHeight / factor;

	float tileSize = 8.0f;

	
	vector<vec2> locations;
	locations.push_back(vec2(0.0f, 5.0f));
	locations.push_back(vec2(1.0f, 5.0f));
	locations.push_back(vec2(2.0f, 5.0f));
	//locations.push_back(vec2(1.0f, 6.0f));

	SpriteAnimation* anim = new SpriteAnimation(quad);

	auto mapLoc = Utils::getAtlasUVLocations(tex, 8);

	anim->SetAnimUvLocation(mapLoc[std::pair<int, int>(0.0, 5.0)]);
	anim->SetAnimUvLocation(mapLoc[std::pair<int, int>(1.0, 5.0)]);
	anim->SetAnimUvLocation(mapLoc[std::pair<int, int>(2.0, 5.0)]);

	/*for (vec2 location : locations)
	{
		float x = location.x;
		float y = location.y;

		vector<glm::vec2> atlasTexCoord;
		atlasTexCoord.push_back(glm::vec2((x * tileSize) / texAspectWidth, (y * tileSize) / texAspectHeigh));
		atlasTexCoord.push_back(glm::vec2(((x + 1.0f) * tileSize) / texAspectWidth, (y * tileSize) / texAspectHeigh));
		atlasTexCoord.push_back(glm::vec2(((x + 1.0f) * tileSize) / texAspectWidth, ((y + 1.0f) * tileSize) / texAspectHeigh));
		atlasTexCoord.push_back(glm::vec2((x * tileSize) / texAspectWidth, ((y + 1.0f) * tileSize) / texAspectHeigh));

		anim->SetAnimUvLocation(atlasTexCoord);
	}*/
	
	


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

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

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

		//std::cout << "width: " << w << ", height: " << h << std::endl;
		glViewport(0, 0, width, height);
		cam->SetOrtho(-w / 2, w / 2, -h / 2, h / 2);

		anim->Update();

		scene->Update();

		glDrawElements(GL_TRIANGLES, quad->getIndices()->size(), GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}