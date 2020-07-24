// this is how you should alias function pointers


#include <stdio.h>

typedef int bool_t;
typedef bool_t (*less_than_func_t)(int, int);
// looks strange but less_than_func_t is the name 
// getting defined here.
// bool_t is an alias for int
// and
// less_than_func_t is an alias for bool_t (*)(int, int).
// typedef bool_t (*)(int, int) less_than_func_t
// would seem to match the pattern better, but alas no!
// the name needs to be in its proper context
// (note:the name of a new type usually ends with _t)

bool_t less_than(int a, int b) {
    return a < b ? 1 : 0;
}

bool_t less_than_modular(int a, int b){
    return (a%5) < (b%5) ? 1 : 0;
}

int main(){
    less_than_func_t func_ptr = NULL;

    func_ptr = &less_than;
    bool_t result = func_ptr(3, 7);
    printf("%d\n", result);

    func_ptr = &less_than_modular;
    result = func_ptr(3, 7);
    printf("%d\n", result);

    return 0;
}

