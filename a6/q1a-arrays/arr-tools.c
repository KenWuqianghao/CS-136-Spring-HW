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
#include <stdlib.h>
#include "arr-tools.h"
#include "cs136-trace.h"

// See arr-tools.h for documentation.
int minmax_dist(int arr[], int len) {
    int diff;
    int min = 0;
    int max = 0;

    for (int i = 0; i < len; i++) {
        if (arr[i] < arr[min]) {
            min = i;
        }
        if (arr[i] > arr[max]) {
            max = i;
        }
    }

    diff = max - min;
    
    if (diff < 0) {
        diff = diff * -1;
    }

    return diff;
}

// See arr-tools.h for documentation.
int most_occurrences(int arr[], int len) {
    int freq[100] = {0};
    for (int i = 0; i < len; i++) {
        freq[arr[i]]++;
    }
    
    int max_index = 0;
    for (int i = 0; i < 100; i++) {
        if (freq[i] > freq[max_index]) {
            max_index = i;
        }
    }
    
    return max_index;
}

// See arr-tools.h for documentation.
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 2
//               ^                       ->   (2)/1 = 2
//               ^  ^                    -> (2+4)/2 = 3
//                  ^  ^                 -> (4+4)/2 = 4
//                     ^  ^              -> (4+2)/2 = 3
//                        ^  ^           -> (2+6)/2 = 4
//                           ^ ^         -> (6+2)/2 = 4
//                              ^  ^     -> (2+3)/2 = 2(.500)
//                                 ^  ^  -> (3+4)/2 = 4
// example: arr [2, 4, 4, 2, 6, 2, 3, 5], wnd_size 4
//               ^                       ->       (2)/1 = 2
//               ^  ^                    ->     (2+4)/2 = 3
//               ^  ^  ^                 ->   (2+4+4)/3 = 3(.333)
//               ^  ^  ^  ^              -> (2+4+4+2)/4 = 3
//                  ^  ^  ^  ^           -> (4+4+2+6)/4 = 4
//                     ^  ^  ^ ^         -> (4+2+6+2)/4 = 3(.500)
//                        ^  ^  ^  ^     -> (2+6+2+3)/4 = 3(.250)
//                           ^  ^  ^  ^  -> (6+2+3+5)/4 = 4
void moving_average(int arr[], int len, int size) {
    int moving_ave[len];
    int moving_sum = 0;

    for (int i = 0; i < size; i++) {
        for (int j = 0; j <= i; j++) {
            moving_sum += arr[j];
        }
        moving_ave[i] = moving_sum / (i + 1);
        moving_sum = 0;
    }

    for (int i = size; i < len; i++) {
        for (int j = 0; j < size; j++) {
            moving_sum += arr[i - j];
        }
        moving_ave[i] = moving_sum / size;
        moving_sum = 0;
    }

    for (int i = 0; i < len; i++) {
        arr[i] = moving_ave[i];
    }
}