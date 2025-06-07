/*
Copyright 2025 Elis Staaf

Licensed to the Apache Software Foundation (ASF) under one
or more contributor license agreements.  See the LICENSE file
distributed with this work for additional information
regarding copyright ownership.  The ASF licenses this file
to you under the Apache License, Version 2.0 (the
"License"); you may not use this file except in compliance
with the License.  You may obtain a copy of the License at

  http://www.apache.org/licenses/LICENSE-2.0

Unless required by applicable law or agreed to in writing,
software distributed under the License is distributed on an
"AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY
KIND, either express or implied.  See the License for the
specific language governing permissions and limitations
under the License.
*/

#pragma once

#include <io.h>
#include <mem.h>

#include <kernel/ksh.h>
#include <drivers/display.h>
#include <cpu/smbios.h>

/* I did NOT make this art btw */
#define PEARLFETCH_ART \
  "           _.-''|''-._         \n" \
  "        .-'     |     `-.      \n" \
  "      .'\\       |       /`.   \n" \
  "    .'   \\      |      /   `. \n" \
  "    \\     \\     |     /     /\n" \
  "     `\\    \\    |    /    /' \n" \
  "       `\\   \\   |   /   /'   \n" \
  "         `\\  \\  |  /  /'     \n" \
  "        _.-`\\ \\ | / /'-._    \n" \
  "       {_____`\\\\|//'_____}   \n" \
  "               `-'             \n"


void ksh_pearlfetch() {
  printf(PEARLFETCH_ART);
  printf("OS: pearlOS %s\n", OS_VERSION);

  printf("BIOS name: %s\n", smbios_get_bios_name());
  printf("BIOS version: %s\n", smbios_get_bios_version());

  printf("Memory: %d/%d\n", memory_usage(), memory_total());
  printf("Theme: %s\n", theme);
}