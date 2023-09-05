// minmax_dist(arr, len) calculates the number of integers in arr[] between
//   the first appearance of the minimum integer and the first appearance of
//   the maximum integer.
// examples: arr = [100, 200]: distance is 1 (between 100 and 200)
//           arr = [-1, 10, 0, 8, -10, 5]: distance is 3 (between 10 and -10)
//           arr = [-1, 10, 0, 10, -10, 5]: distance is 3 (between 10 and -10)
//           arr = [42]: distance is 0 (between 42 and 42)
// requires: len > 0
int minmax_dist(int arr[], int len);

// most_occurrences(arr, len) finds the most frequent integer in arr[]. If
//   there is a tie, return the integer with the lowest index of its first
//   occurrence.
// requires: len > 0
int most_occurrences(int arr[], int len);

// moving_average(arr, len, wnd_size) calculates the moving average of arr[]
//   with a given window size wnd_size and stores it in arr[].
// effects:  mutates arr[]
// requires: 0 < len <= 100
//           wnd_size must be positive
void moving_average(int arr[], int len, int wnd_size);