#pragma once
#pragma warning(disable: 4150)
#include "Core/Window/Window.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"

namespace Mistletoe
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowProps& props = WindowProps());

		void OnUpdate() override;
		void SetVSync(bool enabled) override;
	private:
		void glfwSetCallbacks();
		GLFWwindow* window;
	};
}