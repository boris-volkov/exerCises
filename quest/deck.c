#include "declarations.h"

typedef struct{
	int top;
	int bot;
	char op_code;
} card_t;

typedef struct{
	struct card_t** cards;
}deck_t;

deck_t* allocate_deck(){
	return (deck_t*) malloc(sizeof(card_t)*NUM_CARDS);
}

void generate_deck(deck_t* deck){


