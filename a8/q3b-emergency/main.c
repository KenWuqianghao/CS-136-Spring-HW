#include <stdio.h>
#include <stdlib.h>
#include "patient.h"
#include "pqueue.h"
#include "cs136-trace.h"

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * ENQ <priority:int> <name:string>
//   Enqueues a new patient with a given priority and name.
// * DEQ
//   Dequeues a patient and prints out their information.
// * FRONT
//   Prints out the information of the patient at the front of the queue.
// * EMPTY
//   Prints out whether the patient queue is empty or not.
// * PRINT
//   Prints the patient queue.
int main(void) {
    const int CMD_ENQ = lookup_symbol("ENQ");
    const int CMD_DEQ = lookup_symbol("DEQ");
    const int CMD_FRONT = lookup_symbol("FRONT");
    const int CMD_EMPTY = lookup_symbol("EMPTY"); 
    const int CMD_PRINT = lookup_symbol("PRINT");

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
            printf("INFO: The patient queue is%sempty.\n", pqueue_empty(pq) ? " " : " not ");
        } else if (cmd == CMD_PRINT) {
            pqueue_print(pq);
        } else {
            printf("ERROR: unknown command\n");
            pqueue_destroy(pq);
            exit(EXIT_SUCCESS);
        }
    }
    pqueue_destroy(pq);
}