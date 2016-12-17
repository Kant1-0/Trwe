
#include "eSDL.h"

namespace eSDL
{
	Engine::Engine() : w_name("eSDL"), w_rx(900), w_ry(600), run(1)
	{
		input = new Input();
		fps = new Fps();
		if (Initialize() < 0)
			exit(EXIT_FAILURE);
	}

	Engine::Engine(std::string name, uint32_t rx, uint32_t ry) : w_name(name), w_rx(rx), w_ry(ry), run (1)
	{
		input = new Input();
		fps = new Fps();
		if (Initialize() < 0)
			exit(EXIT_FAILURE);
	}

	Engine::~Engine()
	{
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}

	int8_t Engine::Initialize()
	{
		int8_t	ret = 0;
		if (SDL_Init(SDL_INIT_VIDEO) != 0)
		{
			ret = -1;
			std::cerr << "SDL_Init() failed: " << SDL_GetError() << "\n";
		}
		win = SDL_CreateWindow(w_name.c_str(), SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, w_rx, w_ry, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
		if (!win)
		{
			ret = -1;
			std::cerr << "SDL_CreateWindow() failed: " << SDL_GetError() << "\n";
		}
		render = SDL_CreateRenderer(win, -1, SDL_RENDERER_ACCELERATED);
		if (!render)
		{
			ret = -1;
			std::cerr << "SDL_CreateRenderer() failed: " << SDL_GetError() << "\n";
		}
		return (ret);
	}

	SDL_Renderer *Engine::Renderer() const
	{
		return (render);
	}

	int8_t Engine::Run() const
	{
		return (run);
	}

	void Engine::UpdateInput()
	{
		input->UpdateInput();
		if (input->quit)
			run = 0;
	}

	void Engine::UpdateFps()
	{
		fps->FpsLimit();
		fps->FpsCounter();
	}

	int Engine::GetWidth() const
	{
		return (w_rx);
	}

	int Engine::GetHeight() const
	{
		return (w_ry);
	}
}