#include <assert.h>
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "sorted-array.h"
#include "cs136-trace.h"

// === THERE IS NO NEED TO MODIFY THE MAIN FUNCTION ===========================

// The program accepts the following commands:
// * INIT
//   Initializes the sorted array.
// * INSERT <value:int>
//   Inserts value val into the sorted array.
// * REMOVE <value:int>
//   Attempts to remove one instance of value val from the sorted array.
// * AT <index:int>
//   Retrieves the value at index from the sorted array.
// * EXIST <value:int>
//   Tests if value is stored in the sorted array.
// * PRINT
//   Prints the sorted array.
int main(void) {

  const int CMD_INIT = lookup_symbol("INIT");
  const int CMD_INSERT = lookup_symbol("INSERT");
  const int CMD_REMOVE = lookup_symbol("REMOVE");
  const int CMD_AT = lookup_symbol("AT");
  const int CMD_EXISTS = lookup_symbol("EXIST");
  const int CMD_PRINT = lookup_symbol("PRINT");

  struct sarray sa = { };

  int CMD = INVALID_SYMBOL;
  while ((CMD = read_symbol()) != INVALID_SYMBOL) {
    if (CMD == CMD_INIT) {
      sarray_init(&sa);
    } else if (CMD == CMD_INSERT) {
      int value = INT_MIN;
      assert(scanf("%d", &value) == 1);
      sarray_insert(&sa, value);
      printf("INFO: %d inserted into sorted array.\n", value);
    } else if (CMD == CMD_REMOVE) {
      int value = INT_MIN;
      assert(scanf("%d", &value) == 1);
      sarray_remove(&sa, value);
      printf("INFO: %d removed from sorted array.\n", value);
    } else if (CMD == CMD_AT) {
      int index = INT_MIN;
      assert(scanf("%d", &index) == 1);
      printf("INFO: value #%d at index %d\n", sarray_at(&sa, index), index);
    } else if (CMD == CMD_EXISTS) {
      int value = INT_MIN;
      assert(scanf("%d", &value) == 1);
      if (sarray_exist(&sa, value)) {
        printf("INFO: %d exists\n", value);
      } else {
        printf("INFO: %d does not exist\n", value);
      }
    } else if (CMD == CMD_PRINT) {
      sarray_print(&sa);
    } else {
      printf("ERROR: unknown command\n");
      exit(EXIT_SUCCESS);
    }
  }
  return EXIT_SUCCESS;
}
