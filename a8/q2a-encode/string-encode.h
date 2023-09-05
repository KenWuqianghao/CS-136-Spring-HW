// str_encode(str) encodes the string str using run-length encoding.
//   The format of the encoding is [DC]*, where D is a single digit between
//   1 and 9, and C is a single character. D significes how many times the
//   character C occurs.
// example: str_encode("AABccc!!") => "2A1B3c2!"
// effects: allocates heap memory [caller must free]
// time:    O(n)
char *str_encode(const char *str);