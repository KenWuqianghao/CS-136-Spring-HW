#include "thread.h"

// cdll represents a circular doubly-linked list for storing threads
struct cdll;

// cdll_create(slice) returns an empty circular doubly-linked list. The
//   parameter slice represents the time (in ms) allocated for each thread
//   during thread execution.
// effects: allocates heap memory [client must call cdll_destroy]
// time:    O(1)
struct cdll *cdll_create(int slice);

// cdll_destroy(cdll) releases all resources used by *cdll.
// effects: invalidates *cdll
// time:    O(n), where n is the length of *cdll
void cdll_destroy(struct cdll *cdll);

// cdll_insert(cdll, thrd) inserts *thrd at the front of *cdll.
// effects: mutates *cdll
// time:    O(1)
void cdll_insert(struct cdll *cdll, struct thread *thrd);

// cdll_remove(cdll) removes the thread from the front of *cdll. If *cdll is
//   empty, the function does not mutate *cdll.
// effects: might mutate *cdll
// time:    O(1)
void cdll_remove(struct cdll *cdll);

// cdll_move_next(cdll) moves *cdll to the next thread. If *cdll is empty, the
//   function does not mutate *cdll.
// effects: might mutate *cdll
// time:    O(1)
void cdll_move_next(struct cdll *cdll);

// cdll_move_prev(cdll) moves *cdll to the previous thread. If *cdll is empty,
//   the function does not mutate *cdll.
// effects: might mutate *cdll
// time:    O(1)
void cdll_move_prev(struct cdll *cdll);

// cdll_front(cdll) returns the first thread from *cdll or NULL if *cdll is
//    empty.
// time: O(1)
struct thread *cdll_front(const struct cdll *cdll);

// cdll_exec(cdll) executes all threads in *cdll exactly once.
// effects: mutates *cdll
//          produces output
// time:    O(n), where n is the number of threads in *cdll
void cdll_exec(struct cdll *cdll);

// cdll_print(cdll) prints the current content of *cdll to the console.
//   A non-empty cdll is printed in two ways:
//   * forward:  [first -> next -> next -> ... -> (first)]
//   * backward: [first -> prev -> prev -> ... -> (first)]
//   If (???) is printed at the end, than the cycle is not closed correctly.
// effects: produces output
// time:    O(n), where n is the number of threads in *cdll
void cdll_print(const struct cdll *cdll);