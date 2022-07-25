#include "bar.h"
#include <stdio.h>

int g_bar = 0;

int run_bar()
{
	printf("g_bar  = %d\n", g_bar);
	return 0;
}
