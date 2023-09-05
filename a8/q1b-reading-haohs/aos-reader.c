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

// Below is the partial memory diagram at the end of read_haohs, just before
//   returning to main:8.
//
// === HEAP =================
// | addr_1 |          "CS" |
// |  ...   |      ...      |
// | addr_2 |         "136" |
// |  ...   |      ...      |
// | addr_3 |           "!" |
// |  ...   |      ...      |
// | addr_4 |      [addr_1] |
// |        |      [addr_2] |
// |        |      [addr_3] |
// |        |      ...      |
// === STACK ================
// read_haohs
//     haohs: [addr_0]
//     r/a:   main:8
// --------------------------
// main
//     haohs: addr_4 [addr_0]
//     r/a:   OS
// ==========================
void read_haohs(char ***haohs) {
    char name[256];
    int n = 0;
    char **temp = NULL;

    *haohs = (char **)malloc(sizeof(char *));
    while (scanf("%255[^\n]%*c", name) != -1) {
        temp = realloc(*haohs, (n + 1) * sizeof(char *));
        *haohs = temp;

        (*haohs)[n] = (char *)malloc(strlen(name) + 1);
        strcpy((*haohs)[n], name);
        n++;
    }

    temp = (char **)realloc(*haohs, (n + 1) * sizeof(char *));
    *haohs = temp;
    (*haohs)[n] = NULL;
}

void destroy_haohs(char **haohs) {
    for (int i = 0; haohs[i] != NULL; i++) {
        free(haohs[i]);
    }
    free(haohs);
}