#pragma once
#pragma warning(disable: 4150)
#include "Core/Window/Window.h"
#include "GLFW/glfw3.h"

namespace Mistletoe
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow();
		WindowsWindow(const WindowData& data);
		~WindowsWindow() override;

		void OnUpdate() override;
		void SetVSync(bool enabled) override;
	private:
		std::shared_ptr<GLFWwindow> window;
	};
}