#ifndef DEMO8_11_16B_CONSOLE_H
#define DEMO8_11_16B_CONSOLE_H

#include "t3dconsole.h"

// setup a 640x480 16-bit windowed mode example
#define WINDOW_TITLE      "16-Bit Smooth Scrolling Demo"
#define WINDOW_WIDTH      640   // size of window
#define WINDOW_HEIGHT     480

#define WINDOW_BPP        16    // bitdepth of window (8,16,24 etc.)
// note: if windowed and not
// fullscreen then bitdepth must
// be same as system bitdepth
// also if 8-bit the a pallete
// is created and attached

#define WINDOWED_APP      1     // 0 not windowed, 1 windowed
#define NUM_TEXTURES         10 // normally this would be a multiple of 16 or something!


class DEMO8_11_16b_CONSOLE :public ConsoleBase{
public:
	int init(void *param = NULL, int num_parms = 0);
	int main(void *param = NULL, int num_parms = 0);
	int shutdown(void *param = NULL, int num_parms = 0);
};

#endif