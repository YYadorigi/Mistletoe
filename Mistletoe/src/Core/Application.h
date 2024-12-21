#pragma once
#include <stdio.h>
#include <memory>
#include "Core.h"

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