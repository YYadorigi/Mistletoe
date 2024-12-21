#pragma once

#ifdef MST_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Mistletoe::Log::Init();
	MST_CORE_WARN("Initialized Log!");
	MST_INFO("Hello!");

	auto app = Mistletoe::CreateApplication();
	app->Run();
	app.reset();
	return 0;
}
#endif