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

#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "cdll.h"
#include "cs136-trace.h"

// === CIRCULAR DOUBLY-LINKED LIST - NODE =====================================

// THERE IS NO NEED TO MODIFY THE FUNCTIONS IN THIS SECTION.
// YOU MAY DO SO, AT YOUR OWN RISK.

// cdll_node represents a node in a CDLL
struct cdll_node {
  struct thread *thrd;    // the data
  struct cdll_node *next; // the next cdll_node
  struct cdll_node *prev; // the previous cdll_node
};

// cn_create(thrd) returns a new cdll_node that stores thrd.
// effects: allocates heap memory [client must call cn_destroy]
// time:    O(1)
static struct cdll_node *cn_create(struct thread *thrd) {
  assert(thrd);
  struct cdll_node *cn = malloc(sizeof(struct cdll_node));
  assert(cn);
  cn->thrd = thrd;
  cn->next = NULL;
  cn->prev = NULL;
  return cn;
}

// cn_destroy(cn) releases all resources used by cn.
// effects: invalidates cn
// time:    O(1)
static void cn_destroy(struct cdll_node *cn) {
  assert(cn);
  thread_destroy(cn->thrd);
  free(cn);
}

// === CIRCULAR DOUBLY-LINKED LIST - LIST =====================================

struct cdll {
  struct cdll_node *front;
  // Additional fields go here.
};

// See cdll.h for documentation.
struct cdll *cdll_create(int slice) {
  // Your implementation goes here.
  return NULL;
}

// See cdll.h for documentation.
void cdll_destroy(struct cdll *cdll) {
  // Your implementation goes here.
}

// See cdll.h for documentation.
void cdll_insert(struct cdll *cdll, struct thread *thrd) {
  // Your implementation goes here.
}

// See cdll.h for documentation.
void cdll_remove(struct cdll *cdll) {
  // Your implementation goes here.
}

// See cdll.h for documentation.
void cdll_move_next(struct cdll *cdll) {
  // Your implementation goes here.
}

// See cdll.h for documentation.
void cdll_move_prev(struct cdll *cdll) {
  // Your implementation goes here.
}

// See cdll.h for documentation.
struct thread *cdll_front(const struct cdll *cdll) {
  // Your implementation goes here.
  return NULL;
}

// See cdll.h for documentation.
void cdll_exec(struct cdll *cdll) {
  // Print each thread AFTER it was executed.
  // Use the following printf format strings:
  //   * "=== Executing CDLL with %03d ms slices ===\n"
  //   * "=========================================\n"
  // Your implementation goes here.
}

// See cdll.h for documentation.
// THERE IS NO NEED TO MODIFY THE FUNCTION cdll_print.
// YOU MAY DO SO, AT YOUR OWN RISK.
void cdll_print(const struct cdll *cdll) {
  assert(cdll);
  if (cdll->front == NULL) {
    printf("CDLL is empty\n");
  } else {
    struct cdll_node *tmp = cdll->front;
    printf("CDLL (forward):  [%d", thread_id_get(tmp->thrd));
    tmp = tmp->next;
    while (tmp != cdll->front && tmp != NULL) {
      printf(" -> %d", thread_id_get(tmp->thrd));
      tmp = tmp->next;
    }
    if (tmp == cdll->front) {
      printf(" (-> %d)]\n", thread_id_get(tmp->thrd));
    } else {
      printf(" -> (???)]\n");
    }
    printf("     (backward): [%d", thread_id_get(tmp->thrd));
    tmp = cdll->front->prev;
    while (tmp != cdll->front && tmp != NULL) {
      printf(" -> %d", thread_id_get(tmp->thrd));
      tmp = tmp->prev;
    }
    if (tmp == cdll->front) {
      printf(" (-> %d)]\n", thread_id_get(tmp->thrd));
    } else {
      printf(" -> (???)]\n");
    }
  }
}
