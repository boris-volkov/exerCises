#ifndef CAT_H
#define CAT_H

//forward declaration
struct cat_t;

// memory allocator
struct cat_t* cat_new();

// constructor
void cat_constructor(struct cat_t*);

// destructor
void cat_destructor(struct cat_t*);

//all behavior functions are inherited.

#endif
