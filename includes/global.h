
#ifndef GLOBAL_H
# define GLOBAL_H

# define UCHAR			unsigned char
# define UINT			unsigned int
# define BOOL			int
# define TRUE			1
# define FALSE			0

# ifdef __linux__
# define PAGE_SIZE		4096
# endif
# define STACK_SIZE		(2 * PAGE_SIZE)

# define API_NAME		"TR World Editor"
# define MAX_FPS		60
# define WIN_RX			1400
# define WIN_RY			900
# define MENU_RX		300
# define LOAD_NAME		"image/Loader.bmp"
# define LOAD_RX		900
# define LOAD_RY		563

# define HELP			-2
# define ERROR			-1

# define EV_EXIT		-1
# define EV_RESIZE		-2

#endif
