// str_decode(str) decodes the string str using run-length encoding.
//   The format of the encoding is [DC]*, where D is a single digit between
//   1 and 9, and C is a single character. D significes how many times the
//   character C occurs.
// example: str_decode("2A1B3c2!") => "AABccc!!"
// effects: allocates heap memory [caller must free]
// time:    O(n)
char *str_decode(const char *str);