/*
  Manipulate Fps and rendering time
*/

#ifndef ESDL_FPS_H
# define ESDL_FPS_H

# define MAX_FPS	60

namespace eSDL
{
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
}

#endif // !ESDL_FPS_H