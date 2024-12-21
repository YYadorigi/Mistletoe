#pragma once

#ifdef MST_PLATFORM_WINDOWS
// extern std::shared_ptr<Mistletoe::Application> Mistletoe::CreateApplication();
int main(int argc, char** argv)
{
	auto app = Mistletoe::CreateApplication();
	app->Run();
	app.reset();
	return 0;
}
#endif