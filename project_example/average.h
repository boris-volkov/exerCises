// File Name: average.h

#ifndef average_h
#define average_h 

// enumeration is a set of named integer constants
typedef enum {
    NONE,
    NORMAL,
    SQUARED
} average_type_t;

//Function declaration

double avg(int*, int, average_type_t);

#endif

