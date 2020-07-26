#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "public_animal.h"
#include "private_animal.h"

typedef struct {
	animal_t animal;
} duck_t;

// define new behavior for the duck's sound

void __duck_sound(void* ptr){
	animal_t* animal = (animal_t*) ptr;
	printf("%s: QUACK\n", animal->name);
}

// memory alloduckor
duck_t* duck_new(){
	return (duck_t*)malloc(sizeof(duck_t));
}

// constructor
void duck_constructor(duck_t* duck){
	animal_constructor((struct animal_t*)duck);
	strcpy(duck->animal.name, "CAT");
	// override the inherited function
	duck->animal.sound_func = __duck_sound;
}

// destructor
void duck_destructor(duck_t* duck){
	animal_destructor((struct animal_t*)duck);
}


