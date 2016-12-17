/*
  Handle multiple surfaces as listed objets to render easily
*/

#ifndef ESDL_SURFACE_H
# define ESDL_SURFACE_H

#if SDL_BYTEORDER == SDL_BIG_ENDIAN
	#define RMASK 0xFF000000
	#define GMASK 0x00FF0000
	#define BMASK 0x0000FF00
	#define AMASK 0x000000FF
	#define COLOR 0x000000FF
#else
	#define RMASK 0x000000FF
	#define GMASK 0x0000FF00
	#define BMASK 0x00FF0000
	#define AMASK 0xFF000000
	#define COLOR 0xFF000000
#endif

namespace eSDL
{
	class Surface_Elem
	{
	public:
		Surface_Elem(Engine *engine, SDL_Rect rect, uint32_t color = COLOR);
		~Surface_Elem();

		void DrawSurface(Engine *engine);

	private:
		void CreateSurface();

		SDL_Texture		*s_text;
		SDL_Surface		*s_surf;
		SDL_Rect		s_rect;
	};

	class Surface
	{
	public:
		Surface();
		Surface(Engine *engine, SDL_Rect rect, uint32_t color = COLOR);
		~Surface();

		void RenderSurfaces(Engine *engine);

		void PushBack(Engine *engine, SDL_Rect rect, uint32_t color = COLOR);

	private:
		std::vector<Surface_Elem> list;
	};
}

#endif