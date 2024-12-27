#include "mstpch.h"
#include "Application.h"
#include "Log.h"
#include "Events/Event.h"
#include "Events/ApplicationEvent.h"
#include "Events/KeyEvent.h"
#include "Events/MouseEvent.h"
#include "Platform/Windows/WindowsWindow.h"

namespace Mistletoe
{
	Application::Application()
	{
#ifdef MST_PLATFORM_WINDOWS
		window = std::make_unique<WindowsWindow>();
#else
		window = nullptr;
#endif
		window->SetEventCallback(std::bind(&Application::OnEvent, this, std::placeholders::_1));

		layerStack = std::make_unique<LayerStack>();

		running = true;
	}

	Application::~Application() = default;

	void Application::OnEvent(Event& e)
	{
		EventDispatcher dispatcher(e);
		dispatcher.Dispatch<WindowCloseEvent>([this](Event& e) {
			running = false;
			return true;
		});

		MST_CORE_INFO("{0}", e.ToString());

		if (layerStack->empty()) {
			for (auto it = layerStack->end(); it != layerStack->begin(); ) {
				(*--it)->OnEvent(e);
				if (e.IsHandled()) {
					break;
				}
			};
		}
	}

	void Application::PushLayer(const std::shared_ptr<Layer>& layer)
	{
		layerStack->PushLayer(layer);
	}

	void Application::PushOverlay(const std::shared_ptr<Layer>& overlay)
	{
		layerStack->PushOverlay(overlay);
	}

	void Application::Run()
	{
		while (running) {
			if (!layerStack->empty()) {
				for (auto it = layerStack->begin(); it != layerStack->end(); it++) {
					(*it)->OnUpdate();
				};
			}

			window->OnUpdate();
		}
	}
}