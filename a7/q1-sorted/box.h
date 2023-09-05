#ifndef _BOX
#define _BOX
struct box {
    char id;
    int volume;
    int weight;
};
#endif //_BOX

// box_init(id, vol, wght) returns an intialized box with label id, volume
//   vol, and weight wght.
// time: O(1)
struct box box_init(char id, int vol, int wght);

// box_sort_weight_asc(bx1, bx2) compares two boxes bx1 and bx2 by weight.
//   (The function returns a negative number if bx1 comes before bx2, a
//    positive number if bx2 comes before bx1, and 0 if they are equivalent.)
// time: O(1)
int box_sort_weight_asc(const struct box *bx1, const struct box *bx2);

// box_sort_weight_desc(bx1, bx2) compares two boxes bx1 and bx2 by weight.
//   (The function returns a positive number if box1 comes before box2, a
//    negative number if bx2 comes before bx1, and 0 if they are equivalent.)
// time: O(1)
int box_sort_weight_desc(const struct box *bx1, const struct box *bx2);

// box_sort_volume_asc(bx1, bx2) compares two boxes bx1 and bx2 by volume.
//   (The function returns a negative number if box1 comes before box2, a
//    positive number if bx2 comes before bx1, and 0 if they are equivalent.)
// time: O(1)
int box_sort_volume_asc(const struct box *bx1, const struct box *bx2);

// box_print(box) prints the box bx.
// effects: produces output
// time:    O(1)
void box_print(const struct box *bx);