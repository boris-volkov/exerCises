#include <stdio.h>
#include "average.h"

int main(){
    int array[] = { 10, 3, 5, -8, 9 };

    double average = avg(array, 5, NORMAL);
    // the reason avg has any meaning here is because 
    // array.c is part of the same package and the
    // it is declared in the header and the linker will
    // find the definition in the other .c file. 
    // reason NORMAL has any meaning is because of the 
    // enumeration defined in the header. 

    printf("The average: %f\n", average);

    printf("The squared average: %f\n", avg(array, 5, SQUARED));

    return 0;
}

