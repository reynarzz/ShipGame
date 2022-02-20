#pragma once
#include <glfw/glfw3.h>

typedef struct Input Input;

class Input {
public:

	static bool _A_Pressed;
	static bool _D_Pressed;

	static bool _W_Pressed;
	static bool _S_Pressed;
	static bool _Space_Pressed;

	static void Update(GLFWwindow* window) {

		_A_Pressed = glfwGetKey(window, GLFW_KEY_A);
		_D_Pressed = glfwGetKey(window, GLFW_KEY_D);
		_S_Pressed = glfwGetKey(window, GLFW_KEY_S);
		_W_Pressed = glfwGetKey(window, GLFW_KEY_W);
		_Space_Pressed = glfwGetKey(window, GLFW_KEY_SPACE);
	}
};
