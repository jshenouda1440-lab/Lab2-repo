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
	size_t count = 0;
	for(int i = 0; s[count] !=0; i++){
	count++;

	}
    /* TODO: walk to the '\0'. my_strlen("") must be 0. */
    
    return count;
}

char *my_strdup(const char *s) {

	size_t length = my_strlen(s);
	char *CopyOfS = (char*)(malloc((sizeof(char)*length)+sizeof(char))); // AI helped me format for malloc
	if(CopyOfS == NULL){return NULL;}
	int i;
	for(i = 0; s[i]!=0; i++){
	CopyOfS[i] = s[i];
	}
	CopyOfS[i] = '\0'; //didnt know the syntax for null terminated. had to look that up.


    /* TODO: malloc exactly the right number of bytes (how many?),
     * copy s including the terminator, return the new buffer.
     * Return NULL if malloc fails. Remember: in C++, malloc's
     * void* must be cast: (char *)malloc(...). */
    (void)s;
    return CopyOfS;
}

int my_strcmp(const char *a, const char *b) {
	int i; 
	for(i =0; (a[i] != 0 && b[i] != 0); i++){
	if(a[i] != b[i]){return((unsigned char)a[i] - (unsigned char)b[i]);}

		}



    /* TODO: the strcmp contract. Compare as UNSIGNED CHAR --
     * plain char is signed on mario, and "\xFF" vs "a" will
     * come out with the wrong sign if you compare as char. */
        
    return(unsigned char)a[i] - (unsigned char)b[i];
}

int my_strcpy_safe(char *dst, size_t dstsize, const char *src) {
	size_t LengthOfsrc = my_strlen(src);
	if(dstsize == 0){return 0;} 
	if(dstsize <= LengthOfsrc){
	dst[0] = '\0';
	return 0;
	}
	int i;
	for(i =0; src[i] != 0 ; i++){
	dst[i] = src[i] ;
	}
	dst[i] = '\0';
    /* TODO: copy src into dst, never writing more than dstsize
     * bytes INCLUDING the terminator. On success return 1.
     * If src does not fit, leave dst a valid empty string and
     * return 0. Think about dstsize == 0 before you write. */
    return 1;
}
