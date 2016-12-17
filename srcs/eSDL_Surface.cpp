
#include "eSDL.h"

namespace eSDL
{
	Surface_Elem::Surface_Elem(Engine *engine, SDL_Rect rect, uint32_t color) : s_rect(rect)
	{
		CreateSurface();
		SDL_FillRect(s_surf, NULL, color);
		s_text = SDL_CreateTextureFromSurface(engine->Renderer(), s_surf);
		SDL_FreeSurface(s_surf);
	}

	Surface_Elem::~Surface_Elem()
	{ }

	void Surface_Elem::CreateSurface()
	{
		s_surf = SDL_CreateRGBSurface(0, s_rect.w, s_rect.h, 32, RMASK, GMASK, BMASK, AMASK);
		if (s_surf == NULL)
			std::cerr << "SDL_CreateRGBSurface() failed: "<< SDL_GetError() << "\n";
	}

	void Surface_Elem::DrawSurface(Engine *engine)
	{
		SDL_RenderCopy(engine->Renderer(), s_text, NULL, &s_rect);
	}

	Surface::Surface()
	{ }

	Surface::Surface(Engine *engine, SDL_Rect rect, uint32_t color)
	{
		list.push_back(Surface_Elem(engine, rect, color));
	}

	void Surface::PushBack(Engine *engine, SDL_Rect rect, uint32_t color)
	{
		list.push_back(Surface_Elem(engine, rect, color));
	}

	Surface::~Surface()
	{ }

	void Surface::RenderSurfaces(Engine *engine)
	{

		SDL_RenderClear(engine->Renderer());
		for (std::vector<Surface_Elem>::iterator it = list.begin(); it != list.end(); ++it)
		{
			it->DrawSurface(engine);
		}
		SDL_RenderPresent(engine->Renderer());
	}
}