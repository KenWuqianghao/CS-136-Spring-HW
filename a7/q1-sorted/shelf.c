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

#include "shelf.h"
#include "box.h"
#include "cs136-trace.h"
#include "stdio.h"
// maximum number of boxes that can be stored on the shelf
static const int SHELF_CAPACITY = 10;

struct shelf shelf_init(void) {
  struct shelf new_shelf;
  for (int i = 0; i < SHELF_CAPACITY; ++i) {
    new_shelf.boxes[i].id = '\0';
    new_shelf.boxes[i].volume = 0;
    new_shelf.boxes[i].weight = 0;
    new_shelf.pboxes[i] = &(new_shelf.boxes[i]);
  }
  new_shelf.count = 0;
  return new_shelf;
}
// See box.h for documentation.
// This function fails if the shelf capacity has been exceeded.
bool shelf_push(struct shelf *sh, char id, int volume, int weight) {
    assert(id >= 'A' && id <= 'z');
    assert(volume > 0);
    assert(weight > 0);
    if (sh->count >= SHELF_CAPACITY) {
        return false;
    }

    struct box new_box = box_init(id, volume, weight);
    sh->boxes[sh->count] = new_box;
    sh->pboxes[sh->count] = &sh->boxes[sh->count];
    sh->count++;
    return true;
}

// See box.h for documentation.
// This function fails if the shelf is empty.
bool shelf_pop(struct shelf *sh, struct box *popped) {
    if (sh->count == 0) {
        return false;
    }
    *popped = sh->boxes[sh->count - 1];

    bool found = false;
    for (int i = 0; i < sh->count; i++) {
        if (sh->pboxes[i] == &sh->boxes[sh->count - 1]) {
            found = true;
        } if (found) {
            sh->pboxes[i] = sh->pboxes[i + 1];
        }
    }

    sh->count--;
    return true;
}

// See box.h for documentation.
// This function fails if the shelf is empty.
bool shelf_top(const struct shelf *sh, const struct box **top) {
    if (sh->count == 0) {
        return false;
    } else {
        *top = &(sh->boxes[sh->count - 1]);
        return true;
    }
}

// See box.h for documentation.
void shelf_sort(struct shelf *sh, int(comp)(const struct box *, const struct box *)) {
  for (int i = 0; i < sh->count; ++i) {
    for (int j = i + 1; j < sh->count; ++j) {
      if (comp(sh->pboxes[i], sh->pboxes[j]) > 0) {
        struct box *tmp = sh->pboxes[i];
        sh->pboxes[i] = sh->pboxes[j];
        sh->pboxes[j] = tmp;
      }
    }
  }
}

// See box.h for documentation.
void shelf_print(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (actual) =========\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(&(sh->boxes[i]));
    }
    printf("============================\n");
}

// See box.h for documentation.
void shelf_print_refs(const struct shelf *sh) {
    assert(sh);
    printf("=== SHELF (references) =====\n");
    for (int i = 0; i < sh->count; ++i) {
        box_print(sh->pboxes[i]);
    }
    printf("============================\n");
}