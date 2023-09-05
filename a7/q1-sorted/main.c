#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "box.h"
#include "shelf.h"
#include "cs136-trace.h"

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * PUSH <id:char> <volume:int> <weight:int>
//   Adds a box to the top of the shelf with a given id (does not have to be
//   unique), volume, and weight.
// * POP
//   Attempts to remove the box from the top of the shelf.
// * TOP
//   Attempts to access the box from the top of the shelf.
// * SORT_WA
//   Sorts the box labels by weight (ascending)
// * SORT_WD
//   Sorts the box labels by weight (descending)
int main(void) {
    
    const int CMD_PUSH = lookup_symbol("PUSH");
    const int CMD_POP = lookup_symbol("POP");
    const int CMD_TOP = lookup_symbol("TOP");
    const int CMD_SORT_WA = lookup_symbol("SORT_WA");
    const int CMD_SORT_WD = lookup_symbol("SORT_WD");
    const int CMD_SORT_V = lookup_symbol("SORT_V");
    const int CMD_PRINT = lookup_symbol("PRINT");
    const int CMD_PRINT_REFS = lookup_symbol("PRINT_REFS");

    struct shelf cont = shelf_init();

    int cmd = INVALID_SYMBOL;
    while ((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (cmd == CMD_PUSH) {
            char uid = '\0';
            int volume = INT_MIN, weight = INT_MIN;
            assert(scanf("%c%d%d", &uid, &volume, &weight));
            if(shelf_push(&cont, uid, volume, weight) ) {
                printf("INFO: New box added to shelf.\n");
            } else {
                printf("WARNING: The shelf is already full.\n");
            }
        } else if (cmd == CMD_POP) {
            struct box popped = {0};
            if (shelf_pop(&cont, &popped) ) {
                box_print(&popped);
            } else {
                printf("WARNING: The shelf is empty.\n");
            }
        } else if (cmd == CMD_TOP) {
            const struct box *top = NULL;
            if (shelf_top(&cont, &top)) {
                box_print(top);
            } else {
                printf("WARNING: The shelf is empty.\n");
            }
        } else if (cmd == CMD_SORT_WA) {
            shelf_sort(&cont, box_sort_weight_asc);
            printf("Shelf references sorted by weight (ascending).\n");
        } else if (cmd == CMD_SORT_WD) {
            shelf_sort(&cont, box_sort_weight_desc);
            printf("Shelf references sorted by weight (descending).\n");
        } else if (cmd == CMD_SORT_V) {
            shelf_sort(&cont, box_sort_volume_asc);
            printf("Shelf references sorted by volume (ascending).\n");
        } else if (cmd == CMD_PRINT) {
            shelf_print(&cont);
        } else if (cmd == CMD_PRINT_REFS) {
            shelf_print_refs(&cont);
        } else {
            printf("ERROR: Unknown command.\n");
            exit(0);
        }
    }
}
