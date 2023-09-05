#include <stdio.h>
#include <stdlib.h>
#include "patient.h"

int main(void) {
    struct patient *p1 = patient_read();
    patient_print(p1);
    struct patient *p1_clone = patient_clone(p1);
    patient_print(p1_clone);
    patient_destroy(p1_clone);
    patient_destroy(p1);
}