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

#include <err.h>
#include <io.h>
#include <mem.h>
#include <conv.h>
#include <fs/core.h>
#include <drivers/display.h>
#include <string>

/* DISCLAIMER
 * Fuck this, dude. It keeps kmallocing a value called "S",
 * which presumably happened during the cpu update. Fix later
 * maybe. */

excode ksh_filesz() {
    /* Collect */
    printk("> ");
    char *file = (char *) kmalloc(255);
    scan(file); /* This is where file = "S" */

    /* Handle */
    char *file_sz;
    int_to_str(file_sz, file_size(file));
    printf("%s\n", file_sz);

    return exitval;
}