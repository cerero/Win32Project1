#include <stdlib.h>
#ifndef T3DCONSOLE_H
#define T3DCONSOLE_H

class ConsoleBase{
public:
	virtual int init(void *param = NULL, int num_parms = 0) = 0;
	virtual int main(void *param = NULL, int num_parms = 0) = 0;
	virtual int shutdown(void *param = NULL, int num_parms = 0) = 0;
};

#endif