#include <assert.h>
#include <stdio.h>
#include "box.h"

// See box.h for documentation.
struct box box_init(char uid, int vol, int wght) {
    assert(('A' <= uid && uid <= 'Z') || ('a' <= uid && uid <= 'z'));
    assert(vol > 0);
    assert(wght > 0);
    struct box box = {uid, vol, wght};
    return box;
}

// See box.h for documentation.
int box_sort_weight_asc(const struct box *box1, const struct box *box2) {
    assert(box1);
    assert(box2);
    int result = box1->weight - box2->weight;
    if (result != 0) {
        return result;
    }
    result = box1->volume - box2->volume;
    if (result != 0) {
        return result;
    }
    return box1->id - box2->id;
}

// See box.h for documentation.
int box_sort_weight_desc(const struct box *box1, const struct box *box2) {
    assert(box1);
    assert(box2);

    int result = box2->weight - box1->weight;
    if (result != 0) {
        return result;
    }
    result = box1->volume - box2->volume;
    if (result != 0) {
        return result;
    }
    return box1->id - box2->id;
}

// See box.h for documentation.
int box_sort_volume_asc(const struct box *box1, const struct box *box2) {
    assert(box1);
    assert(box2);
    int result = box1->volume - box2->volume;
    if (result != 0) {
        return result;
    }
    result = box1->weight - box2->weight;
    if (result != 0) {
        return result;
    }
    return box1->id - box2->id;
}

// See box.h for documentation.
void box_print(const struct box *box) {
    assert(box);
    printf("ID: %c; Weight: %d kg; Volume: %d cm^3\n", box->id, box->weight, box->volume);
}