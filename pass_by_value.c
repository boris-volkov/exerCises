// passing by reference does not exist in C
// everything is passed by value


#include <stdio.h>

void func(int* a){
    int b = 9;
    *a = 5; // this function changes what a is pointing to
    a = &b; // but changing a itself here does not change a outside
}

int main(){
    int x = 3;
    int* xptr = &x;
    printf("Value before call: %d\n", x);
    printf("Pointer before function call: %p\n", (void*)xptr);
    func(xptr);
    printf("Value after call: %d\n", x);
    // the value of x is still the same even thought it is 
    // 'changed' inside of the call to func
    printf("Pointer after function call: %p\n", (void*)xptr);
    return 0;
}
