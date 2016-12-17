
#include "eSDL.h"

namespace eSDL
{
	Input::Input() : key{0}, button{0}, mw_y(0), m_x(0), m_y(0), m_r_x(0), m_r_y(0), quit(0), window(0)
	{ }

	Input::~Input()
	{ }

	void Input::UpdateInput()
	{
		uint16_t ret = 0;
		SDL_GetMouseState(&m_x, &m_y);
		SDL_GetRelativeMouseState(&m_r_x, &m_r_y);
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT || CheckInput(SDL_SCANCODE_ESCAPE))
				quit = 1;
			else if (event.type == SDL_WINDOWEVENT)
			{
				if (event.window.event == SDL_WINDOWEVENT_RESIZED)
					window = SDL_WINDOWEVENT_RESIZED;
			}
			if ((ret += GetInput()) > 0)
				break;
			if ((ret += GetMouse()) > 0)
				break;
		}
	}

	int Input::CheckInput(int in)
	{
		if (key[in])
			return (1);
		return (0);
	}

	int Input::GetInput()
	{
		uint16_t ret = 0;
		if (event.type == SDL_KEYDOWN)
		{
			key[event.key.keysym.scancode] = 1;
			ret++;
		}
		else if (event.type == SDL_KEYUP)
		{
			key[event.key.keysym.scancode] = 0;
			ret++;
		}
		return (ret);
	}

	int Input::GetMouse()
	{
		uint16_t ret = 0;
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			button[event.button.button] = 1;
			ret = SDL_MOUSEBUTTONDOWN;
		}
		else if (event.type == SDL_MOUSEBUTTONUP)
		{
			button[event.button.button] = 0;
			ret = SDL_MOUSEBUTTONUP;
		}
		return (ret);
	}

	Fps::Fps() : fps(0), current(0), update(0), framelimit(0), limit(MAX_FPS)
	{
		FpsLimit();
	}

	Fps::~Fps()
	{ }

	void Fps::FpsLimit()
	{
		uint32_t ticks = SDL_GetTicks();
		int32_t max = (1000 / limit);
		if (framelimit < ticks)
			return;
		if (framelimit > ticks + max)
			SDL_Delay(max);
		else
			SDL_Delay(framelimit - ticks);
		framelimit = SDL_GetTicks() + (1000 / limit);
	}

	void Fps::FpsCounter()
	{
		if ((update = SDL_GetTicks()) - current >= 1000)
		{
			current = update;
			fps = 0;
		}
		++fps;
	}

	Engine::Engine() : w_name("eSDL"), w_rx(900), w_ry(600), run(1)
	{
		input = new Input();
		fps = new Fps();
		Initialize();
	}

	Engine::Engine(std::string name, uint32_t rx, uint32_t ry) : w_name(name), w_rx(rx), w_ry(ry), run (1)
	{
		input = new Input();
		fps = new Fps();
		Initialize();
	}

	Engine::~Engine()
	{
		SDL_DestroyRenderer(render);
		SDL_DestroyWindow(win);
		SDL_Quit();
	}

	int Engine::Initialize()
	{
		int		ret;

		ret = 0;
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

	int Engine::Run()
	{
		return (run);
	}

	void Engine::GetInput()
	{
		input->UpdateInput();
		if (input->quit)
			run = 0;
	}

	void Engine::GetFps()
	{
		fps->FpsLimit();
		fps->FpsCounter();
	}
}