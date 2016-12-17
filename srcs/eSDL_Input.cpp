
#include "eSDL.h"

namespace eSDL
{
	Input::Input() : key{ 0 }, button{ 0 }, mw_y(0), m_x(0), m_y(0), m_r_x(0), m_r_y(0), quit(0), window(0)
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

	uint8_t Input::CheckInput(int16_t in)
	{
		if (key[in])
			return (1);
		return (0);
	}

	uint16_t Input::GetInput()
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

	uint16_t Input::GetMouse()
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
}