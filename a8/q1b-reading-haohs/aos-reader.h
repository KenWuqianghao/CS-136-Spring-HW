// read_haohs(haohs) reads all data from input by line, and stores the input
//   as an array of lines in *haohs (heap-array of heap-strings).
// effects: allocates heap-memory [client must call destroy_haohs]
// time:    O(m*n) [amortized], where m is the maximum length of each line and
//                                    n is the number of lines
void read_haohs(char ***haohs);

// destroy_haohs(haohs) releases all resources used by haohs.
// effects: invalidates *haohs
// time:    O(n), where n is the length of the haohs
void destroy_haohs(char **haohs);