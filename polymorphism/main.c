#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//only public interfaces
#include "public_animal.h"
#include "public_cat.h"
#include "public_duck.h"


int main(){
	struct animal_t* animal = animal_new();
	struct cat_t* cat = cat_new();
	struct duck_t* duck = duck_new();

	animal_constructor(animal);
	cat_constructor(cat);
	duck_constructor(duck);

// need to cast to call animal function
	animal_sound(animal);
	animal_sound((struct animal_t*) cat);
	animal_sound((struct animal_t*) duck);

	animal_destructor(animal);
	cat_destructor(cat); 
	duck_destructor(duck);

	free(animal);
	free(cat);
	free(duck);

	return 0;
}

