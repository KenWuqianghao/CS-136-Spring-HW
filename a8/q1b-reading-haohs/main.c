#include <stdio.h>
#include <stdlib.h>
#include "aos-reader.h"

int main(void) {
    char **haohs = NULL;
    read_haohs(&haohs);
    for (char **hstr = haohs; *hstr != NULL; ++hstr) {
        printf("%s\n", *hstr);
    }
    destroy_haohs(haohs);
}