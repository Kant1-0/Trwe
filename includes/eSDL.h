/*
  Cpp wrapper to easily handle SDL2
*/

#ifndef ESDL_H
# define ESDL_H

# include <iostream>
# include <string>

# include <SDL.h>
# include <SDL_ttf.h>

# define MAX_FPS	60

namespace eSDL
{
	class Input
	{
	public:
		Input();
		~Input();

		void UpdateInput();
		int CheckInput(int in);

		int8_t		key[SDL_NUM_SCANCODES];
		int8_t		button[8];
		int32_t		mw_y;
		int32_t		m_x;
		int32_t		m_y;
		int32_t		m_r_x;
		int32_t		m_r_y;
		int8_t		quit;
		int8_t		window;

	private:
		int GetMouse();
		int GetInput();

		SDL_Event	event;
	};

	class Fps
	{
	public:
		Fps();
		~Fps();

		void FpsLimit();
		void FpsCounter();

	protected:

		int32_t		fps;
		int32_t		current;
		int32_t		update;
		int32_t		limit;
		uint32_t	framelimit;

		char		title[128];
	};

	class Engine
	{
	public:
		Engine();
		Engine(std::string name, uint32_t rx, uint32_t ry);
		~Engine();

		int Run();
		void GetInput();
		void GetFps();

	private:
		int Initialize();

		SDL_Window		*win;
		SDL_Renderer	*render;
		uint32_t		w_rx;
		uint32_t		w_ry;

		std::string		w_name;

		Input			*input;
		Fps				*fps;

		int8_t			run;
	};
}

#endif // !ESDL_H