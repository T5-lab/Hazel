#include "hzpch.h"

#include "WindowsInput.h"
#include "GLFW/glfw3.h"
#include "Hazel/Application.h"

namespace Hazel
{
	Input* Input::s_Instance = new WindowsInput();

	bool WindowsInput::IsKeyPressedImpl(int keycode)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		int state = glfwGetKey(window, keycode);
		return state == GLFW_PRESS || state == GLFW_REPEAT;
	}
	bool WindowsInput::IsMouseButtonPressedImpl(int button)
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();
		int state = glfwGetMouseButton(window, button);
		return state == GLFW_PRESS;
	}
	std::pair<float, float> WindowsInput::GetMousePositionImpl()
	{
		GLFWwindow* window = (GLFWwindow*)Application::Get().GetWindow().GetNativeWindow();

		double xPos, yPos;
		glfwGetCursorPos(window, &xPos, &yPos);

		return { (float)xPos, (float)yPos };
	}
	float WindowsInput::GetMouseXImpl()
	{
		auto[x, y] = GetMousePositionImpl();
		return x;
	}
	float WindowsInput::GetMouseYImpl()
	{
		auto[x, y] = GetMousePositionImpl();
		return y;
	}
}