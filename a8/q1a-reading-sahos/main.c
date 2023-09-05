#include <stdio.h>
#include <stdlib.h>
#include "aos-reader.h"

int main(void) {
    int len = 10;
    char *saohs[10] = {NULL};
    read_saohs(saohs, len);
	for (char **hstr = saohs; hstr < saohs + len && *hstr != NULL; ++hstr) {
        printf("%s\n", *hstr);
    }
    destroy_saohs(saohs, len);
}