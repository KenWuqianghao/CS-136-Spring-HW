#include <assert.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "selectionsort-ptr.h"
#include "cs136-trace.h"

// is_sorted(arr, len) returns true if *arr is sorted inascending order, and
//   false otherwise.
bool is_sorted(const int *arr, int len) {
  assert(arr);
  assert(len > 0);
  for (const int *p = arr; p < arr + len - 1; ++p) {
    if (*p > *(p + 1)) {
      return false;
    }
  }
  return true;
}

void public_tests(void) {
    int len = 12;
    int arr[] = {-852, 423, -216, 56, -907, 674, 877, 563, -471, 228, -201, 560};
    trace_array_int(arr, len);
    assert(is_sorted(arr, len) == false);
    array_sort_ptr(arr, arr + len - 1);
    trace_array_int(arr, len);
    assert(is_sorted(arr, len) == true);
}

void private_tests(void) {
}

int main(void) {
    public_tests();
    private_tests();
    trace_msg("All tests passed!");
}
