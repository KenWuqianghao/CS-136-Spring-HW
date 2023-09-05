#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common/string-reader.h"
#include "string-encode.h"

int main(void) {
    char *input = read_all_input();
    char *encoded = str_encode(input);
    free(input);
    printf("%s\n", encoded);
    free(encoded);
}