#include <stdio.h>

// size_t is an unsigned data type for storing sizes in C
void print_bytes(void* data, size_t length)
{
    char delim = ' ';
    unsigned char* ptr = data;
    for (size_t i = 0; i < length; i++){
        printf("%c 0x%x", delim, *ptr++);
        delim = ',';
    }
    printf("\n");
}

int main()
{
    int a = 9;
    double b = 18.9;

    print_bytes(&a, sizeof(int));
    print_bytes(&b, sizeof(double));

    return 0;
}
