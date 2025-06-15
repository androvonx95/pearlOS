/*
 * Copyright (c) Salmon 2025 under the ANTIFA-MIT license.
 * If your copy of this program doesn't include the license, it is
 * available to read at: 
 *
 *     https://github.com/jamiebuilds/anti-fascist-mit-license
 */

#pragma once

#include <io.h>
#include <mem.h>
#include <drivers/display.h>
#include <fs/core.h>

void ksh_make_file() {
  printk("> ");
  char* file_to_make = (char*) kmalloc(512);
  scan(file_to_make);

  int response = file_make(file_to_make);

  if (response == FILE_ALREADY_EXISTS) {
    println("File already exists!");
  }
  else if (response == FILE_NAME_INVALID) {
    printf("File name can only contain the following characters:\n%s\n",
           FS_FILE_NAME_VALID_CHARS);
  }
  else if (response == FILE_COUNT_MAX_EXCEEDED) {
    println("There are too many files!");
  }

  kfree(file_to_make);
}