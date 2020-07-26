#ifndef DUCK_H
#define DUCK_H

//forward declaration
struct duck_t;

// memory alloduckor
struct duck_t* duck_new();

// constructor
void duck_constructor(struct duck_t*);

// destructor
void duck_destructor(struct duck_t*);

//all behavior functions are inherited.

#endif
