#pragma once
#include <memory>
#include "Core/Core.h"
#include "Core/Window/Window.h"

namespace Mistletoe
{
	class MST_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	private:
		std::unique_ptr<Window> window;
		bool running;
	};

	std::shared_ptr<Application> CreateApplication();
}