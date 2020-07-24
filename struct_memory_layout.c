#include <stdio.h>

struct sample_t{
    char first;
    char second;
    char third;
    short fourth;
};

// words in a 64 bit system are 4 bytes wide,
// so if you were to put the 2 byte short right
// after the three byte chars, it would be on a 
// word boundary and therefore take two reads to 
// access. instead this struct is stored as 
// char char char 0 short1 short2
// if for some reason you wanted it to be packed,
// you declare the struct this way:

struct __attribute__((__packed__)) packed_t {
    char first;
    char second;
    char third;
    short fourth;
}
// this is good only if memory is very short but 
// its bad for access speed.

void print_size( struct sample_t* var ){
    printf("Size: %lu bytes\n", sizeof(*var));
}

void print_bytes( struct sample_t* var) {
    unsigned char* ptr = (unsigned char*) var;
    for (int i = 0; i < sizeof(*var); i++, ptr++)
        printf("%d ", (unsigned int)*ptr);
    printf("\n");
}

int main()
{
    struct sample_t var;
    var.first = 'A';
    var.second = 'B';
    var.third = 'C';
    var.fourth = 765;
    print_size(&var);
    print_bytes(&var);
    return 0;
}

