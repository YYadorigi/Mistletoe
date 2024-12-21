#include "Application.h"
#include "Core/Log.h"
#include "Core/Events/Event.h"
#include "Core/Events/ApplicationEvent.h"
#include "Core/Events/MouseEvent.h"
#include "Core/Events/KeyEvent.h"

namespace Mistletoe
{
	Application::Application() {}

	Application::~Application() {}

	void Application::Run()
	{
		WindowResizeEvent e(1280, 720);
		MST_TRACE(e.ToString());
		while (true);
	}
}