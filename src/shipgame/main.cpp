#include <iostream>
#include <glew.h>
#include <glfw/glfw3.h>
#include <string>
#include <glm/glm.hpp>
#include "Utils.h"
#include "Camera.h"
#include "GameEntity.h"
#include "Input.h"
#include "GameHelper.h"
#include "FrameBuffer.h"
#include "NavecitaGame.h"
#include <chrono>
#include "Time.h"

using namespace Engine;
using glm::mat4;
using glm::mat;

int main() {

	if (!glfwInit()) {

		std::cout << "can't init glfw";

		return -1;
	}

	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	int multiplier = 2;
	int nativeWidth = 144 * multiplier;
	int nativeHeight = 256 * multiplier;

	GLFWwindow* window = glfwCreateWindow(nativeWidth, nativeHeight, "Navecita", NULL, nullptr);

	glfwMakeContextCurrent(window);

	glfwSetInputMode(window, GLFW_STICKY_KEYS, false);
	if (glewInit() != GLEW_OK) {
		std::cout << "can't init glew";
		return -1;
	}

	int width, height;
	glfwGetWindowSize(window, &width, &height);

	_scene = new Scene(nullptr);

	Camera* cam = new Camera();

	//Setup
	cam->_viewTransform->SetPosition(0, 0, -10);

	_projM_ = cam->getProj();
	_viewM_ = cam->getView();

	_projMInv_ = cam->getProjInv();
	_viewMInv_ = cam->getViewInv();
	_screenSize_ = { width, height };

	_boundingBoxIndices_.push_back(0);
	_boundingBoxIndices_.push_back(1);
	_boundingBoxIndices_.push_back(1);
	_boundingBoxIndices_.push_back(2);

	_boundingBoxIndices_.push_back(2);
	_boundingBoxIndices_.push_back(3);
	_boundingBoxIndices_.push_back(3);
	_boundingBoxIndices_.push_back(0);

	_scene->SetCamera(cam);

	FrameBuffer frameBuffer(nativeWidth*2, nativeHeight*2);

	frameBuffer.Bind();
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	frameBuffer.Unbind();

	auto sh = ShadersHelper::GetScreenQuad();

	Shader screenQuadShader(sh.first, sh.second);
	Mesh* quad = Utils::GetQuadMesh();


	Navecita::NavecitaGame* game = new Navecita::NavecitaGame();

	auto t_start = std::chrono::high_resolution_clock::now();

	while (!glfwWindowShouldClose(window))
	{
		auto t_end = std::chrono::high_resolution_clock::now();

		double elapsed_time_ms = std::chrono::duration<double, std::milli>(t_end - t_start).count() / 1000;

		t_start = t_end;

		std::cout << elapsed_time_ms << std::endl;
		glfwGetWindowSize(window, &width, &height);

		Input::Update(window);
		Time::DeltaTime = elapsed_time_ms;

		int isMouse = glfwGetMouseButton(window, 0);

		{
			frameBuffer.Bind();
			frameBuffer.UpdateBuffer(width, height);
			glViewport(0, 0, frameBuffer.GetWidth(), frameBuffer.GetHeight());

			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
			glEnable(GL_BLEND);
			glDepthFunc(GL_LEQUAL);

			glEnable(GL_DEPTH);
			//glEnable(GL_DEPTH_TEST);
			glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

			glClearColor(0.2f, 0.2f, 0.2f, 1.f);


			float targetH = 16.0f * 2;
			float targetW = 9.0f * 2;// 9.0f;

			float scale_w = (float)width / targetW;
			float scale_h = (float)height / targetH;
			float w, h;

			if (scale_w < scale_h)
				w = targetW, h = height / scale_w;
			else
				h = targetH, w = width / scale_h;


			cam->SetOrtho(-w / 2, w / 2, -h / 2, h / 2);
			//cam->SetOrtho(0, width, 0, height);

			_projM_ = cam->getProj();
			_viewM_ = cam->getView();

			_projMInv_ = cam->getProjInv();
			_viewMInv_ = cam->getViewInv();
			_screenSize_ = { width, height };

			_scene->Update();
			frameBuffer.Unbind();
		}

		glViewport(0, 0, width, height);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glDisable(GL_BLEND);
		glDisable(GL_DEPTH_TEST);

		screenQuadShader.Bind();
		quad->Bind();
		glBindTexture(GL_TEXTURE_2D, frameBuffer.GetTexID());

		int loc = glGetUniformLocation(screenQuadShader.getProgram(), "_tex0");
		glUniform1i(loc, 0);

		glDrawElements(GL_TRIANGLES, quad->getIndices().size(), GL_UNSIGNED_INT, NULL);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}
