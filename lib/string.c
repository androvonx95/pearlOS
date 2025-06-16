/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#include <string.h>
#include <stddef.h>
#include <kernel/kmsg.h>

/* Get string length */
uint strlen(char* string) {
  uint length = 0;
  while (*string != 0) {
    ++length;
    ++string;
  }
  return length;
}

/* Copy string.
 * [NOTE] Does NOT check for string size! -> 
 *        string overflow!!! */
void strcpy(char* dest, char* src) {
  uint size  = strlen(src) + 1;
  uint i = 0;

  do {
    dest[i] = src[i];
  } while (++i < size);
}

/* Compare 2 strings (checks if they are equal) */
bool strcmp(char* a, char* b) {
  uint32_t i = 0;
  while (1) {
    if (a[i] != b[i]) {
      return false;
    }
    else if (a[i] == 0 && b[i] == 0) {
      return true;
    }
    ++i;
  }
}

/* Add extension to base string.
 * [NOTE] As stradd() uses strcpy, this
 *        can also cause a string overflow!!!*/
void stradd(char* base, char* extension) {
  strcpy(base + strlen(base), extension);
}

/* Fill string with zero */
void strcls(char* string) {
  while (*string != 0) {
    *string = 0;
    ++string;
  }
}

/* Convert char to uppercase */
char char_to_upper(char character) {
  char offset = 'A' - 'a';
  if (character >= 'a' && character <= 'z') {
    return character + offset;
  }
  return character;
}

/* Do char_to_upper() on 
 * each character in a string. */
void strupp(char* string) {
  while (*string != 0) {
    *string = char_to_upper(*string);
    ++string;
  }
}