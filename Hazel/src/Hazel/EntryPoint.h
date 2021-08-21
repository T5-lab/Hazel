#pragma once

extern Hazel::Application* Hazel::CreateApplication();

#ifdef HZ_PLATFORM_WINDOWS
int main(int argc, char** argv)
{
	Hazel::Log::Init();

	auto app = Hazel::CreateApplication();
	app->Run();
	delete app;
}
#endif