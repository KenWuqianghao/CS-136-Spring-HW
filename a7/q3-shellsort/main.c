#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "shell-sort.h"
#include "cs136-trace.h"

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * ARRAY [<value:int>, ...]
//   Stores up to 1000 values in an array
int main(void) {
    const int CMD_ARRAY = lookup_symbol("ARRAY");

    int data[999] = {0};
    int len = 999;
    int cmd = INVALID_SYMBOL;
    while ((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (cmd == CMD_ARRAY) {
            int index = 0;
            while ((scanf("%d", data + index) == 1) && index < len) {
                ++index;
            }
            shell_sort(data, index);
        } else {
            printf("ERROR: unknown command.\n");
            exit(EXIT_SUCCESS);
        }
    }
}