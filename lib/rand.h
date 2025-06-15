/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

/* Includes */
#include <stddef.h>

/* Defines */
#define LCG_A 1103515245
#define LCG_C 12345
#define LCG_M 2147483648

/* Functions */
void rand_init();
int rand_lcg(int x);
int rand();