#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"
#include "thread.h"
#include "cs136-trace.h"

// Accepted commands for the I/O-driver:
//   SCHED <int:ID> <string:NAME> <int:CPUTIME> Adds a thread with ID, NAME,
//         and CPUTIME to the beginning of the CDLL. ID must be non-negative,
//         length of NAME must not exceed 99 characters, and CPUTIME must be
//         positive.
//   NEXT Moves the CDLL to the next item.
//   PREV Moves the CDLL to the previous item.
//   TERM Removes the item currently at the front of the CDLL.
int main(void) {
  
  struct cdll *cdll = cdll_create(100);
  
  const int cmd_sched = lookup_symbol("SCHED");
  const int cmd_next = lookup_symbol("NEXT");
  const int cmd_prev = lookup_symbol("PREV");
  const int cmd_front = lookup_symbol("FRONT");
  const int cmd_term = lookup_symbol("TERM");
  const int cmd_exec = lookup_symbol("EXEC");
  
  int cmd = INVALID_SYMBOL;
  while ((cmd = read_symbol()) != INVALID_SYMBOL) {
    if (cmd == cmd_sched) {
      cdll_insert(cdll, thread_make());
      cdll_print(cdll);
    } else if (cmd == cmd_next) {
      cdll_move_next(cdll);
      cdll_print(cdll);
    } else if (cmd == cmd_prev) {
      cdll_move_prev(cdll);
      cdll_print(cdll);
    } else if (cmd == cmd_front) {
      struct thread *t = cdll_front(cdll);
      if (t == NULL) {
        printf("CDLL is empty.\n");
      } else {
        printf("Current front is ");
        thread_print(t);
      }
    } else if (cmd == cmd_term) {
      cdll_remove(cdll);
      cdll_print(cdll);
    } else if (cmd == cmd_exec) {
      cdll_exec(cdll);
    } else {
      printf("ERROR: unknown command\n");
      break;
    }
  }
  cdll_destroy(cdll);
}