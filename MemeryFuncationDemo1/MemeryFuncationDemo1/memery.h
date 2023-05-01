#pragma once

#include <stdio.h>


void* my_memcpy(void* dest, const void* src, size_t count);
int my_memcmp(const void* buff1, const void* buff2, size_t count);
void* my_memmove(void* dest, const void* src, size_t count);
void* my_memset(void* dest, int c, size_t count);