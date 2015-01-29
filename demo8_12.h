#ifndef DEMO8_12_H
#define DEMO8_12_H
#include "t3dconsole.h"

// size of universe, could be anything
#define MAX_UNIVERSE_X 6400
#define MAX_UNIVERSE_Y 4800

#define NUM_OBJECTS_UNIVERSE 256 // number of objects in the universe

// used to flag type of object
#define GENERATOR_OBJ   0
#define BEACON_OBJ      1  
#define ALIEN_OBJ       2  

// need something to hold each object
typedef struct SPARSE_OBJ_TYP
{
	int type;  // type of object: beacon, generator, or alien
	// could have just used a bob_ptr here, but I like
	// doing this the hard way so you can exactly what's happening

	int x, y;   // position of object 

} SPARSE_OBJ, *SPARSE_OBJ_PTR;

class demo8_12 :public ConsoleBase{
public:
	int init(void *param = NULL, int num_parms = 0);
	int main(void *param = NULL, int num_parms = 0);
	int shutdown(void *param = NULL, int num_parms = 0);
};

#endif