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
#include "string-encode.h"
#include "cs136-trace.h"

// str_encode(str) encodes the string str using run-length encoding.
//   The format of the encoding is [DC]*, where D is a single digit between
//   1 and 9, and C is a single character. D significes how many times the
//   character C occurs.
// example: str_encode("AABccc!!") => "2A1B3c2!"
// effects: allocates heap memory [caller must free]
// time:    O(n)
char *str_encode(const char *str) {
    assert(str);
    int size = strlen(str);
    char *encoded = malloc(sizeof(char));
    int len = 1;
    int curr = 0;
    int i = 0;

    while (i < size) {
        int counter = 1;
        while (str[i] == str[i + 1] && counter < 9) {
            counter++;
            i++;
        }

        len += 2;
        encoded = realloc(encoded, sizeof(char) * len);
        encoded[curr] = counter + '0';
        encoded[curr + 1] = str[i];
        curr += 2;
        i++;
    }
    encoded[curr] = '\0';
    return encoded;
}