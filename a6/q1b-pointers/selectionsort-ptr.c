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
#include "selectionsort-ptr.h"
#include "cs136-trace.h"

// swap(arr, len, i, j) swaps the values in arr[] at indices i and j.
// effects:  mutates arr[]
// requires: len must be positive
//           i, j must be between 0 and len-1 (including)
void swap(int *i, int *smallest) {
  assert(i);
  assert(smallest);
  int tmp = *i;
  *i = *smallest;
  *smallest = tmp;
}

// See selectionsort-ptr.h for documentation
void array_sort_ptr(int *start, int *end) {
  assert(start);
  assert(end);
  int i = 0;
  while (start + i <= end){
    int *smallest = start + i;
    int *j = start + i;
    while (j <= end){
      if (*j < *smallest){
        smallest = j;
      }
      ++j;
    }
    swap(start + i, smallest);
    ++i;
  }
}