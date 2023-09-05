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
// time: O(1)
void sarray_init(struct sarray *arr) {
  for (int i = 0; i < 100; ++i) {
    arr->data[i] = 0;
  }
  arr->length = 0;
}

// See sorted_array.h for documentation
// time: O(n)
void sarray_insert(struct sarray *arr, int value) {
  assert(arr);
  assert(arr->length < 100);
  assert(value >= 0 && value <= 999999);

  int i = 0;
  while (i < arr->length && arr->data[i] < value) {
    i++;
  }
  for (int j = arr->length; j > i; j--) {
    arr->data[j] = arr->data[j - 1];
  }
  arr->data[i] = value;
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
// time: O(1)
int sarray_at(struct sarray *arr, int index) {
  return arr->data[index];
}

// See sorted_array.h for documentation
// time: O(log n)
bool sarray_exist(struct sarray *arr, int value) {
  // binary search
  int low = 0;
  int high = arr->length - 1;
  while (low <= high) {
    int mid = (low + high) / 2;
    if (arr->data[mid] == value) {
      return true;
    } else if (arr->data[mid] < value) {
      low = mid + 1;
    } else {
      high = mid - 1;
    }
  }

  return false;
}

// See sorted_array.h for documentation
// time: O(n)
void sarray_print(struct sarray *arr) {
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