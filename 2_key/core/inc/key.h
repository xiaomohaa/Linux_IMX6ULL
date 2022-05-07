#ifndef __KEY_H
#define __KEY_H

#include "imx6ul.h"

enum keyValue   {
    KEY_NONE    = 0,
    KEY0_VALUE,
};

void keyInit(void);
int keyScan(void);
int keySolve(int keySta);

#endif

