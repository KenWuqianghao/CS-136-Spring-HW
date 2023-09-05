// read_single_line() reads a single line from input into a single string. If
//   there is no input available, the function returns NULL.
// effects: might allocate heap memory [caller might have to free]
// time:    O(n) [amortized]
char *read_single_line(void);

// read_all_input() reads all data from input into a single string. If there
//   is no input available, the function returns NULL.
// effects: might allocate heap memory [caller might have to free]
// time:    O(n) [amortized]
char *read_all_input(void);