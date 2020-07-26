#ifndef PRIVATE_ANIMAL
#define PRIVATE_ANIMAL

// function pointer type needed to point to
// different morphs of animal sound

typedef void (*sound_func_t)(void*);

// forward declaration
typedef struct {
	char* name;
	// this is a pointer to the sound function.
	sound_func_t sound_func;
} animal_t;

#endif
