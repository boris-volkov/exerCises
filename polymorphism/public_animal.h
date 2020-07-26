#ifndef ANIMAL
#define ANIMAL

//forward declaration
struct animal_t;

//memory allocator
struct animal_t* animal_new();

//constructor
void animal_constructor(struct animal_t*);

//destructor
void animal_destructor(struct animal_t*);

//behavior functions
void animal_get_name(struct animal_t*, char*);
void animal_sound(struct animal_t*);

#endif


