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
#include "shell-sort.h"
#include "cs136-trace.h"

// === HELPER FUNCTIONS =======================================================

// array_print(arr, len) outputs the content of the array arr.
// requires: len must be positive
// effects:  produces output
// time:     O(n)
static void array_print(const int *arr, int len) {
  assert(arr);
  assert(len > 0);
  printf("[%d", *arr);
  for (const int *p = arr + 1; p < arr + len; ++p) {
    printf(", %d", *p);
  }
  printf("]\n");
}

// === MODULE FUNCTIONS =======================================================

void shell_sort(int arr[], int len) {
  assert(len > 0);  
  array_print(arr, len);

  int gap = len/2;

  while (gap > 0) {
    for (int i = gap; i < len; i++) {
      int temp = arr[i];
      int j = i;
      while (j >= gap && arr[j - gap] > temp) {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = temp;
    }
    array_print(arr, len);
    gap = gap/2;
  }

}