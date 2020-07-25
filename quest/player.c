#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct {
	char name[16];
	unsigned long long experience;
	unsigned long time;
	void* deck;
} player_t;

player_t* allocate_player(){
	return (player_t*) malloc(sizeof(player_t));
}

void player_constructor(player_t* player, 
												char* name, 
												unsigned long long experience){
	strcpy(player->name, name);
	player->experience = experience;
	//player->deck = (void *) generate_deck(experience);
}

void player_gain_experience(player_t* player){
	(player->experience)++;
}

void player_update_clock(player_t* player, 
													unsigned long elapsed){
	(player->time) += elapsed;
}

void save_player(	player_t* player, FILE* file){
	free(player);
}

unsigned int player_get_experience(player_t* player){
	return player->experience;
}

void player_play(player_t* player){
	for (int i = 0; i < 10; i++){
		clock_t START_TIME = clock();
		clock_t END_TIME = START_TIME;
		while (END_TIME < START_TIME+1000000){
			END_TIME = clock();
		}
		printf(". ");
		fflush(stdout);
	}
	printf("\n");
}	

int main(int argc, char** argv){
	char* name = "boris";
	player_t* boris = allocate_player();
	player_constructor(boris, name, 5);

	printf("size of boris: %lu\n", sizeof(*boris));
	printf("boris's experience: %lu\n", player_get_experience(boris));
	printf("Great job %s\n", boris->name);

	player_play(boris);
	save_player(boris,stderr);

	return 0;
}
