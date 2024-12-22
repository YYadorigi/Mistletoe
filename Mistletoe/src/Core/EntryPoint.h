#ifdef MST_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Mistletoe::Log::Init();
	auto app = Mistletoe::CreateApplication();
	app->Run();
	app.reset();
	return 0;
}
#endif