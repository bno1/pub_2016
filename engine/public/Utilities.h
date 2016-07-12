#pragma once

#include <stdlib.h>
#include <stdio.h>

#define RUNTIME_ASSERT(expression)                         \
	if (!(expression)) {                                     \
		fprintf(stderr, "RUTNIME_ASSERT failed in function %s (%s:%d)\n", __FUNCTION__, __FILE__, __LINE__); \
		exit(1);                                          \
	}