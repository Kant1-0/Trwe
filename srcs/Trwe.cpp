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
		engine = new eSDL::Engine("TR World Editor", 1680, 960);

		//Background
		surfaces = new eSDL::Surface(engine, SDL_Rect{ 0, 0, engine->GetWidth(), engine->GetHeight() }, 0xff302d2d);

		//Panels
		surfaces->PushBack(engine, SDL_Rect{ 0, 40, 350, engine->GetHeight() - 60 }, 0xff262525);
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 350, 40, 350, engine->GetHeight() - 60 }, 0xff262525);

		//Map set
		surfaces->PushBack(engine, SDL_Rect{ 10, 45, 150, 20 }, 0xff423e3e);
		surfaces->PushBack(engine, SDL_Rect{ 5, 65, 335, 370 }, 0xff423e3e);
		//Object set
		surfaces->PushBack(engine, SDL_Rect{ 10, 450, 150, 20 }, 0xff423e3e);
		surfaces->PushBack(engine, SDL_Rect{ 5, 470, 335, 460 }, 0xff423e3e);

		//Render view
		surfaces->PushBack(engine, SDL_Rect{ 350, 40, engine->GetWidth() - 700, engine->GetHeight() - 50 }, 0xff686868);

		//Select tab
		surfaces->PushBack(engine, SDL_Rect{ 350, engine->GetHeight() - 90, engine->GetWidth() - 700, 70 }, 0xff423e3e);

		//Texture set
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 335, 45, 150, 20 }, 0xff423e3e);
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 340, 65, 335, 660 }, 0xff423e3e);
		//Effect set
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 335, 740, 150, 20 }, 0xff423e3e);
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 340, 760, 335, 170 }, 0xff423e3e);

		//Dark borders
		surfaces->PushBack(engine, SDL_Rect{ 0, engine->GetHeight() - 20, engine->GetWidth(), 20 }, 0xff1e1e1e);
		surfaces->PushBack(engine, SDL_Rect{ 0, 35, engine->GetWidth(), 5 }, 0xff1e1e1e);
		surfaces->PushBack(engine, SDL_Rect{ engine->GetWidth() - 350, 40, 5, engine->GetHeight() - 60 }, 0xff1e1e1e);
		surfaces->PushBack(engine, SDL_Rect{ 345, 40, 5, engine->GetHeight() - 60 }, 0xff1e1e1e);
	}

	void App::InitOpenGL()
	{

	}

	void App::MainLoop()
	{
		while (engine->Run())
		{
			engine->UpdateInput();

			surfaces->RenderSurfaces(engine);

			engine->UpdateFps();
		}

		delete (engine);
	}
}