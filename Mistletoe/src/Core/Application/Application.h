#pragma once
#include <memory>
#include "Core/Core.h"

namespace Mistletoe
{
	class MST_API Application
	{
	public:
		Application();
		virtual ~Application();

		virtual void Run();
	};

	std::shared_ptr<Application> CreateApplication();
}