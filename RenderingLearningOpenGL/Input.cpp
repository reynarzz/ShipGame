#include "Input.h"


 bool Input::_A_Pressed = false;
 bool Input::_D_Pressed = false;

 bool Input::_W_Pressed = false;
 bool Input::_S_Pressed = false;
 bool Input::_Space_Pressed = false;
 std::map<int, Input::KeyListener> Input::_listeners;
/*void Engine::KeyboardInput::Init(GLFWwindow* window)
{
	glfwSetKeyCallback(window, key_callback);
}

void Engine::KeyboardInput::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (action == GLFW_PRESS) {
		if (key == GLFW_KEY_A) {
			_A_Pressed = true;
		}
		else if (key == GLFW_KEY_A) {
			_D_Pressed = true;
		}
		else {
			_A_Pressed = false;
			_D_Pressed = false;
		}
	}
}
*/