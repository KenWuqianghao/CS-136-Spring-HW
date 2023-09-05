#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include "arr-tools.h"
#include "cs136-trace.h"

// is_equal(arr1, len1, arr2, len2) returns true if arr1[] and arr2[] are
//   equal, and false otherwise.
bool is_equal(const int arr1[], int len1, const int arr2[], int len2) {
    assert(arr1);
    assert(len1 > 0);
    assert(arr2);
    assert(len2 > 0);
    if (len1 != len2) {
        return false;
    } else {
        for (int i = 0; i < len1; ++i) {
            if (arr1[i] != arr2[i]) {
                return false;
            }
        }
    }
    return true;
}
void public_tests(void) {
    int data0[] = {42};
    assert(minmax_dist(data0, 1) == 0);
    
    int data1[] = {100, 200};
    assert(minmax_dist(data1, 2) == 1);

    int data2[] = {-1, 10, 0, 8, -10, 5};
    assert(minmax_dist(data2, 6) == 3);

    int data3[] = {-1, 10, 0, 10, -10, 5};
    assert(minmax_dist(data3, 6) == 3);

    int data4[] = {2, 2, 1, 2, 2};
    assert(most_occurrences(data4, 5) == 2);

    int data5[] = {2, 2, 3, 1, 3};
    assert(most_occurrences(data5, 5) == 2);

    int data6[] = {2, 4, 4, 2, 6, 2, 3, 5};
    moving_average(data6, 8, 2);
    int data6_avg[] = {2, 3, 4, 3, 4, 4, 2, 4};
    assert(is_equal(data6, 8, data6_avg, 8));

    int data7[] = {2, 4, 4, 2, 6, 2, 3, 5};
    moving_average(data7, 8, 4);
    int data7_avg[] = {2, 3, 3, 3, 4, 3, 3, 4};
    assert(is_equal(data7, 8, data7_avg, 8));
}

void private_tests(void) {
    // add more tests here, if necessary
}

int main(void) {
    public_tests();
    private_tests();
    trace_msg("All tests passed!");
}