#include "mstpch.h"
#include "WindowsWindow.h"

namespace Mistletoe
{
	static bool glfwInitialized = false;

	WindowsWindow::WindowsWindow() : Window()
	{
		if (!glfwInitialized) {
			int success = glfwInit();
			MST_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwInitialized = true;
		}

		window.reset(glfwCreateWindow(data.props.width, data.props.height, data.props.title.c_str(), nullptr, nullptr));
		glfwMakeContextCurrent(window.get());
		glfwSetWindowUserPointer(window.get(), &data);
	}

	Mistletoe::WindowsWindow::WindowsWindow(const WindowData& data) : Window(data)
	{
		if (!glfwInitialized) {
			int success = glfwInit();
			MST_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwInitialized = true;
		}
		window.reset(glfwCreateWindow(data.props.width, data.props.height, data.props.title.c_str(), nullptr, nullptr));
		glfwMakeContextCurrent(window.get());
		glfwSetWindowUserPointer(window.get(), &this->data);
	}

	Mistletoe::WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(window.get());
		window.reset();
	}

	void Mistletoe::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window.get());
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		if (enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}
		Window::SetVSync(enabled);
	}
}