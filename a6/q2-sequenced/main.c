#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "sequence.h"
#include "cs136-trace.h"

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * BUILD [<data:char> ...]
//   reads characters from the console until EOL and stores them in a sequence
// * LOWER
//   converts a sequence into lower-case letters
// * UPPER
//   converts a sequence into upper-case letters
int main(void) {

    const int CMD_BUILD = lookup_symbol("BUILD");
    const int CMD_UPPER = lookup_symbol("UPPER");
    const int CMD_LOWER = lookup_symbol("LOWER");

    struct sequence seq = seq_init();

    int cmd = INVALID_SYMBOL;
    while ((cmd = read_symbol()) != INVALID_SYMBOL) {
        if (cmd == CMD_BUILD) {
            seq = seq_init();
            char input = '\0';
            int pos = 0;
            while (scanf("%c", &input) == 1 && input != '\n') {
                //assert();
                if (!sequence_insert_at(&seq, pos, input)) {
                    printf("ERROR: Sequence ran out of capacity.\n");
                    exit(0);
                }
                ++pos;
            }
            sequence_print(&seq);
        } else if (cmd == CMD_UPPER) {
            int len = sequence_length(&seq);
            for (int i = 0; i < len; ++i) {
                char c = sequence_item_at(&seq, i);
                if ('a' <= c && c <= 'z') {
                    sequence_insert_at(&seq, i, sequence_remove_at(&seq, i) - 'a' + 'A');
                }
            }
            sequence_print(&seq);
        } else if (cmd == CMD_LOWER) {
            int len = sequence_length(&seq);
            for (int i = 0; i < len; ++i) {
                char c = sequence_item_at(&seq, i);
                if ('A' <= c && c <= 'Z') {
                    sequence_insert_at(&seq, i, sequence_remove_at(&seq, i) - 'A' + 'a');
                }
            }
            sequence_print(&seq);
        } else {
            printf("ERROR: Unknown command.\n");
            exit(0);
        }
    }
}