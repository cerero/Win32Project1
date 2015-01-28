
#ifndef DEMO_8_10_CONSOLE_H
#define DEMO_8_10_CONSOLE_H

#include "t3dconsole.h"
#define SCREEN_BPP      8    // bits per pixel
#define MAX_COLORS_PALETTE   256

// skelaton directions
#define SKELATON_EAST         0
#define SKELATON_NEAST        1  
#define SKELATON_NORTH        2
#define SKELATON_NWEST        3
#define SKELATON_WEST         4
#define SKELATON_SWEST        5
#define SKELATON_SOUTH        6
#define SKELATON_SEAST        7

#define START_GLOW_COLOR  152 // starting color index to glow
#define END_GLOW_COLOR    159 // ending color index to glow
#define FLOOR_COLOR       116

class DEMO_8_10_CONSOLE :public ConsoleBase{
public:
	int init(void *param = NULL, int num_parms = 0);
	int main(void *param = NULL, int num_parms = 0);
	int shutdown(void *param = NULL, int num_parms = 0);
};

#endif