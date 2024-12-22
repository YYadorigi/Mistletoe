#include "mstpch.h"
#include "Application.h"
#include "Core/Log/Log.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/KeyEvent.h"
#include "Core/Events/MouseEvent.h"

namespace Mistletoe
{
	Application::Application() {}

	Application::~Application() {}

	void Application::Run()
	{
		Log::Init();
		MST_CORE_TRACE("Application started");
		MST_CORE_INFO("Application running");

		WindowResizeEvent e(1280, 720);
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowResizeEvent>([&](WindowResizeEvent& e) {
			MST_CORE_TRACE(e.ToString());
			return true;
			});

		while (true);
	}
}