


float level;

//deck of cards
//has card objects
//allocate a deck on the heap,
//then randomly pull from it to 
//ask questions.

struct card;

struct deck;

struct deck* allocate_deck();

void deck_constructor(struct deck*);

void deck_destructor(struct deck*);

struct card* deck_get_card(struct deck*)

// function pointer to generate a new card based on level
void deck_replace_card(struct card*, (struct card*) (*f)(float)); 

struct card* generate_card(float);

int card_needs_replacement(struct card*);

void card_print_question(struct card*);



struct player;


