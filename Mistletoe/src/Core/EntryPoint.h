#ifdef MST_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Mistletoe::Log& log = Mistletoe::Log::GetInstance();
	Mistletoe::Application& app = Mistletoe::Application::GetInstance();
	app.Run();
	return 0;
}
#endif