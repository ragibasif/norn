/*
 * File: utils.c
 * Author: Ragib Asif
 * Email: ragibasif@tuta.io
 * GitHub: https://github.com/ragibasif
 * LinkedIn: https://www.linkedin.com/in/ragibasif/
 * SPDX-License-Identifier: MIT
 * Copyright (c) 2025 Ragib Asif
 * Version 1.0.0
 */

#include "utils.h"

#include <assert.h>
#include <stdio.h>

bool alloc_check( void *ptr, const size_t size, const char *file,
                  const int line, const char *func ) {
    if ( !ptr ) {
        fprintf( stderr,
                 "[%s:%u:(%s)] Memory allocation error. Failed to allocate %lu "
                 "bytes to memory address %p.\n",
                 file, line, func, size, (void *)ptr );
        return false;
    }
    return true;
}
