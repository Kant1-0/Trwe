/*
  Init eSDL framework
*/

#ifndef ESDL_INIT_H
# define ESDL_INIT_H

namespace eSDL
{
	class Engine
	{
	public:
		Engine();
		Engine(std::string name, uint32_t rx, uint32_t ry);
		~Engine();

		SDL_Renderer *Renderer() const;

		int8_t Run() const;
		void UpdateInput();
		void UpdateFps();

		int GetWidth() const;
		int GetHeight() const;

	private:
		int8_t Initialize();

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

#endif // !ESDL_INIT_H