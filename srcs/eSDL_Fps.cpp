
#include "eSDL.h"

namespace eSDL
{
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
}