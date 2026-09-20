/*
 * ================================================================
 * Filename:    mystr.cpp
 * Description: ECE 412 Lab 2 -- C string utilities. This is the
 *              same file you wrote for Lab 1. Bring your Lab 1
 *              implementation over, or reimplement here.
 *
 *              Only my_strdup is strictly required by db.cpp for
 *              this lab. The others are here so your `main.cpp`
 *              can keep using the same toolkit you built last week.
 * Created:     TODO
 * EID:         TODO
 * Email:       TODO
 * Author:      TODO
 * Provenance:  I certify that all code contained herein is mine
 *              alone except where otherwise noted.
 * ================================================================
 */

#include <stdlib.h>    /* malloc, free -- NOT <cstring>! */

#include "mystr.h"

size_t my_strlen(const char *s) {
    /* TODO (from Lab 1). */
    (void)s;
    return 0;
}

char *my_strdup(const char *s) {
    /* TODO (from Lab 1). db.cpp depends on this: DB_add's deep copy
     * of the caller's `name` is a my_strdup, and the trap of storing
     * the caller's `const char *` directly is the same dangling-pointer
     * bug we discussed last week. */
    (void)s;
    return NULL;
}

int my_strcmp(const char *a, const char *b) {
    /* TODO (from Lab 1). */
    (void)a;
    (void)b;
    return 0;
}

int my_strcpy_safe(char *dst, size_t dstsize, const char *src) {
    /* TODO (from Lab 1). */
    (void)dst;
    (void)dstsize;
    (void)src;
    return 0;
}
