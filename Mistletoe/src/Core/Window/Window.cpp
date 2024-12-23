#include "mstpch.h"
#include "Window.h"

namespace Mistletoe
{
	WindowProps::WindowProps() : title("Mistletoe Engine"), width(1280), height(720) {}

	WindowProps::WindowProps(const std::string& title, unsigned int width, unsigned int height)
		: title(title), width(width), height(height)
	{}

	WindowData::WindowData(const WindowProps& props) : props(props), vSync(false), eventCallback(nullptr) {}

	Window::Window(const WindowProps& props) : data(props) {}

	Window::~Window() = default;

	Window::Window(const Window&) = default;

	Window& Window::operator=(const Window&) = default;

	Window::Window(Window&&) = default;

	Window& Window::operator=(Window&&) = default;
}