#pragma once
#include <glfw/glfw3.h>
#include <map>

class Input {
private:
	typedef void (*KeyListener)();

public:
	static bool _A_Pressed;
	static bool _D_Pressed;

	static bool _W_Pressed;
	static bool _S_Pressed;
	static bool _Space_Pressed;
	static std::map<int, KeyListener> _listeners;

	static void ListenKey(int key, void(*callback)()) {
		_listeners[key] = callback;
	}

	static void Update(GLFWwindow* window) {

		_A_Pressed = glfwGetKey(window, GLFW_KEY_A);
		_D_Pressed = glfwGetKey(window, GLFW_KEY_D);
		_S_Pressed = glfwGetKey(window, GLFW_KEY_S);
		_W_Pressed = glfwGetKey(window, GLFW_KEY_W);
		_Space_Pressed = glfwGetKey(window, GLFW_KEY_SPACE);
	}
};
