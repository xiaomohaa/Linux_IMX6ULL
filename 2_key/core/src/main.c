#include "control.h"

int main(void)	{
	systemInit();

	while(1)    {	
		systemLoop();
	}

	return 0;
}
