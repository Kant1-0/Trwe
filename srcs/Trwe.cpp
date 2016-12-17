#include "Trwe.h"

namespace Trwe
{
	void App::Run()
	{
		InitSDL();
		InitOpenGL();
		MainLoop();
	}

	void App::InitSDL()
	{
		engine = new eSDL::Engine("TR World Editor", 1280, 960);
	}

	void App::InitOpenGL()
	{

	}

	void App::MainLoop()
	{
		while (engine->Run())
		{
			engine->GetInput();
			engine->GetFps();
		}
	}
}