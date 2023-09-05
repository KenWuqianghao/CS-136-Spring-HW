// read_saohs(haohs, len) reads all data from input by line, up to len lines,
//   and stores the input as an array of lines in *saohs (stack-array of
//   heap-strings).
// effects: allocates heap-memory [client must call destroy_saohs]
// time:    O(n) [amortized], where n is the length of input
void read_saohs(char **saohs, int len);

// destroy_saohs(saohs, len) releases all resources used by saohs.
// effects: invalidates *saohs
// time:    O(n), where n is the length of the saohs
void destroy_saohs(char **saohs, int len);