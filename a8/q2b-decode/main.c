#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include "../common/string-reader.h"
#include "string-encode.h"
#include "string-decode.h"

int main(void) {
    char *input = read_all_input();
    char *encoded = str_encode(input);
    free(input);
    char *decoded = str_decode(encoded);
    free(encoded);
    printf("%s\n", decoded);
    free(decoded);
}