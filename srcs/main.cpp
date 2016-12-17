
#include "Trwe.h"

int		main(int argc, char* args[])
{
	Trwe::App app;

	try
	{
		app.Run();
	}
	catch (const std::runtime_error &e)
	{
		std::cerr << e.what() << "\n";
		std::cin.get();
		return EXIT_FAILURE;
	}

	return EXIT_SUCCESS;
}