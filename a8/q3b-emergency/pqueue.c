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

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include "pqueue.h"
#include "patient.h"
#include "cs136-trace.h"

struct pqueue {
    int len;
    int maxlen;
    struct patient **p;
};

struct pqueue *pqueue_create() {
    struct pqueue *pq = malloc(sizeof(struct pqueue));
    pq->len = 0;
    pq->maxlen = 1;
    pq->p = malloc(pq->maxlen * sizeof(struct patient *));
    return pq;
}

void pqueue_destroy(struct pqueue *pq) {
    assert(pq);
    for (int i = 0; i < pq->len; i++) {
        patient_destroy(pq->p[i]);
    }
    free(pq->p);
    free(pq);
}

void pqueue_enqueue(struct pqueue *pq, struct patient *p) {
    assert(pq);
    assert(p);
    if (pq->len == pq->maxlen) {
        pq->maxlen *= 2;
        pq->p = realloc(pq->p, pq->maxlen * sizeof(struct patient *));
    }
    pq->p[pq->len] = p;
    pq->len += 1;
}

struct patient *pqueue_dequeue(struct pqueue *pq) {
    assert(pq);
    assert(pq->len);
    struct patient *p = patient_clone(pq->p[0]);
    patient_destroy(pq->p[0]);

    for (int i = 0; i < pq->len - 1; i++) {
        struct patient *temp = patient_clone(pq->p[i + 1]);
        pq->p[i] = temp ;
        patient_destroy(pq->p[i + 1]);
    }
    pq->len -= 1;
    return p;
}

struct patient *pqueue_front(const struct pqueue *pq) {
    assert(pq);
    assert(pq->len);
    return patient_clone(pq->p[0]);
}

bool pqueue_empty(const struct pqueue *pq) {
    assert(pq);
    return pq->len == 0;
}

void pqueue_print(const struct pqueue *pq) {
    assert(pq);
    printf("Patient queue");
    for (int i = 0; i < pq->len; i++) {
        printf(" -> ");
        patient_print(pq->p[i]);
    }
    printf("\n");
    // use the following printf format string:
    //   "Patient queue"
    //   " -> "
}