#pragma once
#pragma warning(disable: 4251)
#include "Core.h"
#include "Window/Window.h"
#include "Layers/LayerStack.h"

namespace Mistletoe
{
	class MST_API Application
	{
	public:
		~Application();
		Application(const Application&) = delete;
		Application& operator=(const Application&) = delete;
		Application(Application&&) = delete;
		Application& operator=(Application&&) = delete;

		inline static Application& GetInstance()
		{
			static Application instance;
			return instance;
		}

		void OnEvent(Event& e);

		void PushLayer(const std::shared_ptr<Layer>& layer);
		void PushOverlay(const std::shared_ptr<Layer>& overlay);

		void Run();
	private:
		Application();

		std::unique_ptr<Window> window;
		std::unique_ptr<LayerStack> layerStack;
		bool running;
	};
}