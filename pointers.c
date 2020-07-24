#define NULL 0

int declaration()
{
    int var = 100; // var on top of stack segment
    int* ptr = NULL;  // null pointer -> 0 
    // important to nullify if you're not immediately going to point to something
    // pointers MUST be initialized upon declaration or else bugs
    ptr = &var;   // points to the address of the variable
    *ptr = 200;   // changes the value of the variable to 200
    return 0;
}

int arithmetic()
{
    int var = 1;

    int* int_ptr = NULL; // nullify the pointer
    int_ptr = &var;

    char* char_ptr = NULL;
    char_ptr = (char*)&var;

    printf("before arithmetic: int_ptr: %u, char_ptr: %u\n",
            (unsigned int)int_ptr, (unsigned int)char_ptr);

    int_ptr++;
    char_ptr++;

    printf("after arithmetic: int_ptr: %u, char_ptr: %u\n",
            (unsigned int)int_ptr, (unsigned int)char_ptr);

    return 0;
}

int main()
{
    arithmetic();
    return 0;
}

