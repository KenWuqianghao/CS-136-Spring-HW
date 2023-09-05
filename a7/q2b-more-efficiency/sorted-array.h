#include <stdbool.h>

#ifndef _SARRAY
#define _SARRAY
struct sarray {
  int data[100];
  int length;
};
#endif // _SARRAY

// sarray_init(arr) initializes arr to be an empty sarray.
// effects: ???
// time:    O(1)
void sarray_init(struct sarray *arr);

// sarray_insert(arr, val) inserts value val into the sorted array arr.
// requires: arr must have available space to store value
//           value must be between 0 and 999999 (both inclusive)
// effects:  ???
// time:     O(n)
void sarray_insert(struct sarray *arr, int val);

// sarray_remove(arr, val) removes one instance of value val from the sorted
//   array arr, if val exists in arr; otherwise, arr remains unchanged.
// requires: value must be between 0 and 999999 (both inclusive)
// effects:  ???
// time:     O(n)
void sarray_remove(struct sarray *arr, int value);

// sarray_at(arr, idx) returns the value at index idx from the sarray arr.
// requires: index must be between 0 (inclusive) and the length of arr
//           (exclusive)
// effects:  ???
// time:     O(1)
int sarray_at(struct sarray *arr, int index);

// sarray_exist(arr, val) returns true if value val exists in the sorted array
//   arr, and false otherwise.
// requires: value must be between 0 and 999999 (both inclusive)
// effects:  ???
// time:     O(log n)
bool sarray_exist(struct sarray *arr, int value);

// sarray_print(arr) prints the sorted array arr.
// effects: ???
//          produces console output
// time:    O(n)
void sarray_print(struct sarray *arr);
