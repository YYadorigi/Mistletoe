#include "mstpch.h"
#include "WindowsWindow.h"
#include "Core/Log/Log.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

namespace Mistletoe
{
	static bool glfwInitialized = false;

	static void GLFWErrorCallback(int error, const char* description)
	{
		MST_CORE_ERROR("GLFW Error ({0}): {1}", error, description);
	}

	Mistletoe::WindowsWindow::WindowsWindow(const WindowProps& props) : Window(props)
	{
		if (!glfwInitialized) {
			int success = glfwInit();
			MST_CORE_ASSERT(success, "Could not initialize GLFW!");
			glfwSetErrorCallback(GLFWErrorCallback);
			glfwInitialized = true;
		}

		window = glfwCreateWindow(data.props.width, data.props.height, data.props.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(window);
		glfwSetWindowUserPointer(window, &this->data);
		glfwSetCallbacks();
	}

	void WindowsWindow::glfwSetCallbacks()
	{
		glfwSetWindowCloseCallback(window, [](GLFWwindow* window) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			WindowCloseEvent event;
			data.eventCallback(event);
		});

		glfwSetWindowSizeCallback(window, [](GLFWwindow* window, int width, int height) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			WindowResizeEvent event(width, height);
			data.eventCallback(event);
		});

		glfwSetWindowFocusCallback(window, [](GLFWwindow* window, int focused) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			if (focused) {
				WindowFocusEvent event;
				data.eventCallback(event);
			} else {
				WindowLostFocusEvent event;
				data.eventCallback(event);
			}
		});

		glfwSetMouseButtonCallback(window, [](GLFWwindow* window, int button, int action, int mods) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			switch (action) {
				case GLFW_PRESS:
				{
					MouseButtonPressedEvent event(button);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					MouseButtonReleasedEvent event(button);
					data.eventCallback(event);
					break;
				}
			}
		});

		glfwSetCursorPosCallback(window, [](GLFWwindow* window, double xPos, double yPos) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseMovedEvent event(static_cast<float>(xPos), static_cast<float>(yPos));
			data.eventCallback(event);
		});

		glfwSetScrollCallback(window, [](GLFWwindow* window, double xOffset, double yOffset) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			MouseScrolledEvent event(static_cast<float>(xOffset), static_cast<float>(yOffset));
			data.eventCallback(event);
		});

		glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods) {
			WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
			switch (action) {
				case GLFW_PRESS:
				{
					KeyPressedEvent event(key, false);
					data.eventCallback(event);
					break;
				}
				case GLFW_RELEASE:
				{
					KeyReleasedEvent event(key);
					data.eventCallback(event);
					break;
				}
				case GLFW_REPEAT:
				{
					KeyPressedEvent event(key, true);
					data.eventCallback(event);
					break;
				}
			}
		});
	}

	Mistletoe::WindowsWindow::~WindowsWindow()
	{
		glfwDestroyWindow(window);
	}

	WindowsWindow::WindowsWindow(const WindowsWindow&) = default;

	WindowsWindow& WindowsWindow::operator=(const WindowsWindow&) = default;

	WindowsWindow::WindowsWindow(WindowsWindow&&) = default;

	WindowsWindow& WindowsWindow::operator=(WindowsWindow&&) = default;

	void Mistletoe::WindowsWindow::OnUpdate()
	{
		glfwPollEvents();
		glfwSwapBuffers(window);
	}

	void WindowsWindow::SetVSync(bool enabled)
	{
		Window::SetVSync(enabled);
		if (enabled) {
			glfwSwapInterval(1);
		} else {
			glfwSwapInterval(0);
		}
	}
}