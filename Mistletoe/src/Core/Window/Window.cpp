#include "mstpch.h"
#include "Window.h"

namespace Mistletoe
{
	WindowProps::WindowProps()
	{
		title = "Mistletoe Engine";
		width = 1280;
		height = 720;
	}

	WindowProps::WindowProps(const std::string& title, unsigned int width, unsigned int height)
		: title(title), width(width), height(height)
	{}

	WindowData::WindowData() : props(WindowProps()), vSync(false), eventCallback(nullptr) {}

	WindowData::WindowData(const WindowProps& props) : props(props), vSync(false), eventCallback(nullptr) {}

	Window::Window() : data(WindowData())
	{
		MST_CORE_INFO("Creating window Mistletoe Engine (1280, 720)");
	}

	Window::Window(const WindowData& data) : data(data)
	{
		MST_CORE_INFO("Creating window {0} ({1}, {2})", data.props.title, data.props.width, data.props.height);
	}

	Window::~Window() {}
}