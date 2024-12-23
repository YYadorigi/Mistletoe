#pragma once
#include "Core/Core.h"
#include "Core/Window/Window.h"
#include "Core/Layers/LayerStack.h"

namespace Mistletoe
{
	class MST_API Application
	{
	public:
		Application();
		virtual ~Application();

		void OnEvent(Event& e);

		// void PushLayer(const std::shared_ptr<Layer>& layer);
		// void PushOverlay(const std::shared_ptr<Layer>& overlay);

		virtual void Run();
	private:
		std::unique_ptr<Window> window;
		// LayerStack layerStack;
		bool running;
	};

	std::shared_ptr<Application> CreateApplication();
}