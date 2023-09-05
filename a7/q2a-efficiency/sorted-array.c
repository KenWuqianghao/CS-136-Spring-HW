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

#include "sorted-array.h"
#include "merge-sort.h"
#include "cs136-trace.h"
#include <assert.h>
#include <stdio.h>

// See sorted_array.h for documentation
// time: O(n)
void sarray_init(struct sarray *arr) {
  for (int i = 0; i < 100; ++i) {
    arr->data[i] = 0;
  }
  arr->length = 0;
}

// See sorted_array.h for documentation
// time: O(1)
void sarray_insert(struct sarray *arr, int value) {
  assert(arr);
  assert(arr->length < 100);
  assert(value >= 0 && value <= 999999);
  arr->data[arr->length] = value;
  arr->length++;
}
// See sorted_array.h for documentation
// time: O(n)
void sarray_remove(struct sarray *arr, int value) {
  for (int i = 0; i < 100; i++) {
    if (arr->data[i] == value) {
      for (int j = i; j < 100; j++) {
        arr->data[j] = arr->data[j + 1];
      }
      arr->length--;
      break;
    }
  }
}

// See sorted_array.h for documentation
// time: O(n log n)
int sarray_at(struct sarray *arr, int index) {
  merge_sort(arr->data, arr->length);
  return arr->data[index];
}

// See sorted_array.h for documentation
// time: O(n)
bool sarray_exist(struct sarray *arr, int value) {
  for (int i = 0; i < 100; i++) {
    if (arr->data[i] == value) {
      return true;
    }
  }
  return false;
}

// See sorted_array.h for documentation
// time: O(n log n)
void sarray_print(struct sarray *arr) {
  merge_sort(arr->data, arr->length);
  printf("[");
  for (int i = 0; i < arr->length; i++) {
    if (i == arr->length - 1) {
      printf("%d", arr->data[i]);
    } else {
      printf("%d, ", arr->data[i]);
    }
  }
  printf("]\n");
}
