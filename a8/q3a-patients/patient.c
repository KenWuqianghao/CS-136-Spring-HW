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
#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "cs136-trace.h"

// Hint: think about how the existance of MAX_NAME_LEN affects runtime behaviour
const int MAX_NAME_LEN = 30;

struct patient {
    int priority;
    char name[];
};

struct patient *patient_read(void) {
    struct patient *p = malloc(sizeof(struct patient) + 31 * sizeof(char));
    scanf("%d", &p->priority);
    for (int i = 0; i < MAX_NAME_LEN + 1; i++) {
        if (scanf("%c", &p->name[i]) != 1) {
            p->name[i] = '\0';
            break;
        }
    }
    return p;
}

struct patient *patient_clone(const struct patient *p) {
    assert(p);
    struct patient *p_clone = malloc(sizeof(struct patient) + 31 * sizeof(char));
    p_clone->priority = p->priority;
    for (int i = 0; i < MAX_NAME_LEN + 1; i++) {
        p_clone->name[i] = p->name[i];
    }
    return p_clone;
}

void patient_destroy(struct patient *p) {
    assert(p);
    free(p);
}

void patient_print(const struct patient *p) {
    assert(p);
    printf("(%d)", p->priority);
    for (int i = 0; i < 31; i++) {
        if (p->name[i] == '\0') {
            break;
        }
        printf("%c", p->name[i]);
    }
}