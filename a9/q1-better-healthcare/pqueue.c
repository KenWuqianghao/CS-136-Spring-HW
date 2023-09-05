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
#include <stdbool.h>
#include <assert.h>
#include "patient.h"
#include "pqueue.h"
#include <stdlib.h>
#include "cs136-trace.h"

// === struct pqnode =========================================================

struct pqnode {
    struct patient *patient; // data
    struct pqnode *next;     // next node
    struct pqnode *prev;     // previous node
};

// === struct pqueue =========================================================

struct pqueue {
    struct pqnode *front;       // pointer to the first patient in the pqueue
    struct pqnode *back;        // pointer to the last patient in the pqueue
    struct pqnode **priorities; // array that holds pointers to the frist
                               //   patient with a certain priority
};

// See pqueue.h for documentation.
struct pqueue *pqueue_create() {
    struct pqueue *pq = malloc(sizeof(struct pqueue) + 9 * sizeof(struct pqnode *));
    pq->front = NULL;
    pq->back = NULL;
    pq->priorities = malloc(9 * sizeof(struct pqnode *));
    for (int i = 0; i < 9; i++) {
        pq->priorities[i] = NULL;
    }
    return pq;
}

// See pqueue.h for documentation.
void pqueue_destroy(struct pqueue *pq) {
    assert(pq);
    struct pqnode *cur = pq->front;
    while (cur != NULL) {
        struct pqnode *temp = cur;
        cur = cur->next;
        patient_destroy(temp->patient);
        free(temp);
    }
    free(pq->priorities);
    free(pq);
}

// See pqueue.h for documentation.
void pqueue_enqueue(struct pqueue *pq, struct patient *p) {
    struct pqnode *new_node = malloc(sizeof(struct pqnode));
    new_node->patient = p;

    if(pq->front == NULL || patient_priority(p) < patient_priority(pq->front->patient)) {
        new_node->next = pq->front;
        new_node->prev = NULL;
        if(!pq->front)
            pq->back = new_node;
        else
            pq->front->prev = new_node;
        pq->front = new_node;
        return;
    }

    struct pqnode *current = pq->front;
    while(current->next != NULL && patient_priority(p) > patient_priority(current->next->patient)) {
        current = current->next;
    }
    new_node->next = current->next;
    new_node->prev = current;
    if(current->next != NULL) {
        current->next->prev = new_node;
    } else {
        pq->back = new_node;
    }
    current->next = new_node;
    return;
}

// See pqueue.h for documentation.
struct patient *pqueue_dequeue(struct pqueue *pq) {
    assert(pq);
    assert(pq->front);

    struct pqnode *old_front = pq->front;
    struct patient *p = pq->front->patient;
    pq->front = pq->front->next;
    free(old_front);

    if(!pq->front) {
        pq->back = NULL;
        pq->priorities[patient_priority(p)] = NULL;
    }

    if (patient_priority(p) == patient_priority(pq->front->patient)) {
        pq->priorities[patient_priority(p)] = pq->front;
    } else {
        pq->priorities[patient_priority(p)] = NULL;
    }

    pq->front->prev = NULL;

    return p;
}

// See pqueue.h for documentation.
struct patient *pqueue_front(const struct pqueue *pq) {
    assert(pq);
    assert(pq->front);
    return patient_clone(pq->front->patient);
}

// See pqueue.h for documentation.
bool pqueue_empty(const struct pqueue *pq) {
    assert(pq);
    return pq->front == NULL;
}

// See pqueue.h for documentation.
void pqueue_print(const struct pqueue *pq) {
    assert(pq);
    printf("Patient queue");
    struct pqnode *cur = pq->front;
    while (cur != NULL) {
        printf(" -> ");
        patient_print(cur->patient);
        cur = cur->next;
    }
    printf("\n");
}

// See pqueue.h for documentation.
void pqueue_print_reverse(const struct pqueue *pq) {
    assert(pq);
    struct pqnode *cur = pq->back;
    while (cur != NULL) {
        patient_print(cur->patient);
        printf(" <- ");
        cur = cur->prev;
    }
    printf("Patient queue\n");
}