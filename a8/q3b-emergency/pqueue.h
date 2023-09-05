#include <stdbool.h>
#include "patient.h"

// a queue for patients
struct pqueue;

// pqueue_create() creates a new empty queue.
// effects: allocates heap memory [client must call pqueue_destroy]
// time:    O(1)
struct pqueue *pqueue_create();

// pqueue_destroy(pq) releases all resources used by *pq.
// effects: invalidates pq
// time:    O(n)
void pqueue_destroy(struct pqueue *pq);

// pqueue_enqueue(pq, p) adds patient *p to the end of the patient queue *pq.
// effects: mutates *pq
// time:    O(1) [amortized]
void pqueue_enqueue(struct pqueue *pq, struct patient *p);

// pqueue_dequeue(pq) removes and returns the first patient from the patient
//   queue *pq.
// effects: mutates *pq
// time:    O(n)
struct patient *pqueue_dequeue(struct pqueue *pq);

// pqueue_front(pq) returns a copy of the first patient from the patient queue
//   *pq.
// effects: allocates heap memory [client must call patient_destroy]
// time:    O(1)
struct patient *pqueue_front(const struct pqueue *pq);

// pqueue_empty(pq) returns true if the patient queue *pq is empty, and false
//   otherwise.
// time: O(1)
bool pqueue_empty(const struct pqueue *pq);

// pqueue_print(pq) prints all patients to output.
// effects: produces output
// time:    O(n)
void pqueue_print(const struct pqueue *pq);