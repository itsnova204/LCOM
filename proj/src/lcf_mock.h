#pragma once

#ifdef TEST

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define BIT(n) (0x01 << n)

#else

#include <lcom/lcf.h>

#endif