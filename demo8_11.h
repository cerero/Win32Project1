#ifndef DEMO8_11_H
#define DEMO8_11_H
#include "t3dconsole.h"

#define NUM_TEXTURES         10 // normally this would be a multiple of 16 or something!

class demo8_11:public ConsoleBase{
public:
	int init(void *param = NULL, int num_parms = 0);
	int main(void *param = NULL, int num_parms = 0);
	int shutdown(void *param = NULL, int num_parms = 0);
};

#endif