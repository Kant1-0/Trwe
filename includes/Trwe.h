/*
  Starting point of Trew.
*/

#ifndef TRWE_H
# define TRWE_H

# include "stdafx.h"
# include "eSDL.h"

# include "global.h"

namespace Trwe
{
	class App
	{
	public:
		//Init App Point
		void Run();

	private:
		//eSDL
		void InitSDL();
		//OpenGL
		void InitOpenGL();
		//Rendering Loop
		void MainLoop();

		eSDL::Engine *engine;
		eSDL::Surface *surfaces;
	};
}

#endif // !TRWE_H