#ifdef MST_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Mistletoe::Log& log = Mistletoe::Log::GetInstance();
	log.SetLogFormat("%^s[%T] %n: %v%$");

	Mistletoe::Application& app = Mistletoe::Application::GetInstance();
	app.Run();
	return 0;
}
#endif