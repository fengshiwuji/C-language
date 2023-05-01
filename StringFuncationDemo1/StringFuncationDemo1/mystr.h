#pragma once
#include <stdio.h>

size_t my_strlen(const char* str);
char* my_strcpy(char* strDestination, const char* strSource);
char* my_strncpy(char* strDest, const char* strSrc, size_t count);
int my_strcmp(const char* str1, const char* str2);
int my_strncmp(const char* str1, const char* str2, size_t count);
char* my_strcat(char* strDest, const char* strSrc);
char* my_strncat(char* strDest, const char* strSrc, size_t count);

