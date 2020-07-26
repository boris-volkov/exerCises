#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "private_animal.h" 

// default sound function at parent level:

void __animal_sound(void* this_ptr) {
	animal_t* animal = (animal_t*) this_ptr;
	printf("%s: Beeep\n", animal->name);
}

// memory allocator
animal_t* animal_new(){
	return (animal_t*) malloc(sizeof(animal_t)); 
	// type declaration already in private header
}

// constructor
void animal_constructor(animal_t* animal){
	animal->name = (char*)malloc(10*sizeof(char));
	strcpy(animal->name, "ANIMAL");
	// set function pointer to point to default
	animal->sound_func = __animal_sound;
}

//destructor
void animal_destructor(animal_t* animal){
	free(animal->name);
	//anything the object mallocs has to be freed by the object
}

//behavior

void animal_get_name(animal_t* animal, char* buffer) {
	strcpy(buffer, animal->name);
}

void animal_sound(animal_t* animal){
	// call the function in the animal object
	animal->sound_func(animal);
}


