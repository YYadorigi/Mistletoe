#include "mstpch.h"
#include "Application.h"
#include "Core/Log/Log.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Platform/WindowsWindow.h"

namespace Mistletoe
{
	Application::Application()
	{
#ifdef MST_PLATFORM_WINDOWS
		window = std::make_unique<WindowsWindow>();
#else
		window = nullptr;
#endif
		running = true;
	}

	Application::~Application()
	{
		window.reset();
	}

	void Application::Run()
	{
		while (running) {
			window->OnUpdate();
		}
	}
}