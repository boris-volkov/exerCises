#include <stdio.h>
#include <stdlib.h>

int* create_integer(int number)
{
    int local = number;
    return &local;
}
// the function above is a problem because
// by the time the address is returned,
// the local variable is gone, so what
// is the pointer pointing to?
// needs to be done in heap as below:

int* heap_integer(int number)
{
    int* heap_ptr = (int*) malloc(sizeof(int));
    // malloc return a pointer! not an int
    *heap_ptr = number;
    return heap_ptr;
}
// once you are done with a malloc'd pointer
// you need to free it!

int main()
{
    int* bad_pointer = NULL;
    int* good_pointer = NULL;
    bad_pointer = create_integer(10);
    good_pointer = heap_integer(12);
    printf("%d\n", *good_pointer);
    free(good_pointer); // don't forget to free!
    return 0;
}
