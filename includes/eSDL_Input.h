/*
  Organize inputs to handle user events easier
*/

#ifndef ESDL_INPUT_H
# define ESDL_INPUT_H

namespace eSDL
{
	class Input
	{
	public:
		Input();
		~Input();

		void UpdateInput();
		uint8_t CheckInput(int16_t in);

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
		uint16_t GetMouse();
		uint16_t GetInput();

		SDL_Event	event;
	};
}

#endif // !ESDL_INPUT_H