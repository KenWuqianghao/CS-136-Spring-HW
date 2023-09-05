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

#include "string-reader.h"
#include "cs136-trace.h"
#include "aos-reader.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// Below is the partial memory diagram at the end of read_saohs, just before
//   returning to main:9.
//
// === HEAP ===============
// | addr_1 |        "CS" |
// |  ...   |     ...     |
// | addr_2 |       "136" |
// |  ...   |     ...     |
// | addr_3 |         "!" |
// |  ...   |     ...     |
// === STACK ==============
// read_saohs
//     saohs: [addr_0]
//     len:   4
//     r/a:   main: 9
// -----------------------------
// main
//     saohs: {addr_1,
//             addr_2,
//             addr_3,
//             NULL}   [addr_0]
//     r/a:   OS
// ============================
void read_saohs(char **saohs, int len) {
    int n = 0;
    char name[1000]; 
    while (n < len && scanf("%[^\n]%*c", name) != -1) {
        saohs[n] = malloc(sizeof(char) * (strlen(name) + 1));
        if (saohs[n] != NULL) {
            strcpy(saohs[n], name);
        }
        n++;
    }
}

void destroy_saohs(char **saohs, int len) {
    for (int i = 0; i < len; i++) {
        if (saohs[i] != NULL) {
            free(saohs[i]);
            saohs[i] = NULL;
        }
        
    }
}