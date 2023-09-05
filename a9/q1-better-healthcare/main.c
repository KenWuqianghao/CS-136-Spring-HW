#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "pqueue.h"
#include "cs136-trace.h"


// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * ENQ <priority:int> <name:string>
//   Enqueues a new patient with name and priority; priotiy must be between 1
//   and 9 (both included), where 1 is the highest and 9 the lowest priority.
// * DEQ
//   Dequeues and prints the patient at the front of the queue.
// * FRONT
//   Prints the patient at the front of the queue.
// * EMPTY
//   Prints if the queue is empty or not.
// * PRINT
//   Prints the queue in priority order, i.e. starting with the highest
//   priority.
// * PRINT_REV
//   Prints the queue in reverse order, i.e. starting with the lowest
//   priority.
int main(void) {
    const int CMD_ENQ = lookup_symbol("ENQ");
    const int CMD_DEQ = lookup_symbol("DEQ");
    const int CMD_FRONT = lookup_symbol("FRONT");
    const int CMD_EMPTY = lookup_symbol("EMPTY"); 
    const int CMD_PRINT = lookup_symbol("PRINT");
    const int CMD_PRINT_REV = lookup_symbol("PRINT_REV");

    struct pqueue *pq = pqueue_create();

    int cmd = INVALID_SYMBOL;
    while ((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (cmd == CMD_ENQ) {
            pqueue_enqueue(pq, patient_read());
        } else if (cmd == CMD_DEQ) {
            struct patient *p = pqueue_dequeue(pq);
            patient_print(p);
            printf("\n");
            patient_destroy(p);
        } else if (cmd == CMD_FRONT) {
            struct patient *p = pqueue_front(pq);
            patient_print(p);
            printf("\n");
            patient_destroy(p);
        } else if (cmd == CMD_EMPTY) {
            printf("The patient queue is%sempty.\n", pqueue_empty(pq) ? " " : " not ");
        } else if (cmd == CMD_PRINT) {
            pqueue_print(pq);
        } else if (cmd == CMD_PRINT_REV) {
            pqueue_print_reverse(pq);
        } else {
            printf("ERROR: unknown command\n");
            break;
        }
    }
    pqueue_destroy(pq);
}