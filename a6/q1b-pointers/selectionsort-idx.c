#include <assert.h>
#include "selectionsort-idx.h"

// swap(arr, len, i, j) swaps the values in arr[] at indices i and j.
// effects:  mutates arr[]
// requires: len must be positive
//           i, j must be between 0 and len-1 (including)
static void swap(int arr[], int len, int i, int j) {
  assert(arr);
  assert(len > 0);
  assert(0 <= i && i < len);
  assert(0 <= j && j < len);
  int tmp = arr[i];
  arr[i] = arr[j];
  arr[j] = tmp;
}

// see selectionsort.h for documentation
void array_sort_idx(int arr[], int len) {
  assert(arr);
  assert(len > 0);
  for (int i = 0; i < len - 1; ++i) {
    int smallest_idx = i; // index of the smallest value "right" of arr[i]
    for (int j = i; j < len; ++j) {
      if (arr[j] < arr[smallest_idx]) {
        smallest_idx = j;
      }
    }
    swap(arr, len, i, smallest_idx);
  }
}
