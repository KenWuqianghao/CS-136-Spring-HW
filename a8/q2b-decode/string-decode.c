/////////////////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT (v4)
//
// By signing your name and ID below you are stating that you have agreed
// to the online academic integrity statement posted on edX:
// (Course > Assignments > Assignment Information & Policies > Academic Integrity Policy)
/////////////////////////////////////////////////////////////////////////////////////////
// I received help from and/or collaborated with:

//
//
// Name: Ken Wu
// login ID: 20999205
//////////////////////////////////////////////////////////////////////////////////////////

#include <assert.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "string-decode.h"
#include "cs136-trace.h"

char *str_decode(const char *str) {
    assert(str);
    
    int len = 100;
    int curr = 0;
    char *result;
    result = malloc(len * sizeof(char));

    int size = strlen(str);
    for (int i = 0; i < size; i++) {
        if (i % 2 == 0) {
            int rep = str[i] - '0';
            len += rep;
            result = realloc(result, sizeof(char) * len);
            for (int j = 0; j < rep; j++) {
                result[curr] = str[i + 1];
                curr++;
            }
        }
    }
    result[curr] = '\0';
    return result;
}