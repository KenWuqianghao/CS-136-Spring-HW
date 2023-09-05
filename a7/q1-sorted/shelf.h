#include <assert.h>
#include <stdbool.h>
#include "box.h"

#ifndef _SHELF
#define _SHELF
struct shelf {
    struct box boxes[10];
    struct box *pboxes[10];
    int count;
};
#endif // _SHELF

// shelf_init() returns an empty shelf.
// time: O(1)
struct shelf shelf_init(void);

// shelf_push(sh, id, vol, wght) puts a new box with label id, volume vol, and
//   weight wght into the first empty shelf space of sh. The function returns
//   true if the operation was successful, and false otherwise.
// effects:  mutates *sh
// requires: id must be a letter
//           vol and wght must both be positive
// time:     O(1)
bool shelf_push(struct shelf *sh, char id, int vol, int wght);

// shelf_pop(sh, popped) removes the top-most box from shelf sh. The box is
//   then stored in *popped. The function returns true if the operation was
//   successful, and false otherwise.
// effects:  mutates *sh and *popped
// time:     O(n)
bool shelf_pop(struct shelf *sh, struct box *popped);

// shelf_top(sh, top) stores a reference to the top-most box in shelf sh. The
//   function returns true if the operation was successful, and false
//   otherwise.
// effects:  mutates **top
// time:     O(1)
bool shelf_top(const struct shelf *sh, const struct box **top);

// shelf_sort(sh, comp) sorts the references in shelf sh using the comparison
//   function comp.
// effects:  mutates *sh
// time:     O(n^2) * O(comp)
void shelf_sort(struct shelf *sh, int(comp)(const struct box *, const struct box *));

// shelf_print(sh) prints the actual content of shelf *sh.
// effects:  writes to output
// time:     O(n), where n is the length of *sh
void shelf_print(const struct shelf *sh);

// shelf_print_refs(sh) prints (sorted) references of shelf *sh.
// effects:  writes to output
// time:     O(n), where n is the length of *sh
void shelf_print_refs(const struct shelf *sh);