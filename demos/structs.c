#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

struct Person {
	char *name;
	int age;
	int height;
	int weight;
};

struct Person *Person_create(char *name, int age, 
		int height, int weight)
{
	struct Person *who = malloc(sizeof(struct Person));
	assert(who != NULL);

	who->name = strdup(name);
	who->age = age;
	who->height = height;
	who->weight = weight;

	return who;
}

void Person_destroy(struct Person *who)
{
	assert(who != NULL);

	free(who->name);
	free(who);
}

void Person_print(struct Person *who)
{
	printf("Name: %s\n", who->name);
	printf("\tAge: %d\n", who->age);
	printf("\tHeight: %d\n", who->height);
	printf("\tWeight: %d\n", who->weight);
}

int main(int argc, char *argv[])
{
	struct Person *boris = Person_create("Boris", 31, 69, 150);
	struct Person *sian = Person_create("Sian", 627, 1000, -24);
	struct Person *dallas = Person_create("Dallas", 29, 73, 250);

	//print them out and see where they are in memory
	printf("boris is in memory location %p:\n", (void *)boris);
	Person_print(boris);
	
	printf("sian is in memory location %p:\n", (void *)sian);
	Person_print(sian);

	printf("dallas is in memory location %p:\n", (void *)dallas);
	Person_print(dallas);

	printf("the size of a person pointer is %ld:\n", sizeof(boris));
	printf("was that a pointer? size of person is %ld:\n", sizeof(struct Person));
	//change attributes and print again
	boris->age += 20;
	boris->height -= 2;
	boris->weight += 500;
	Person_print(boris);

	sian->age += 20;
	sian->weight -= 300;
	Person_print(sian);

	//destroy them both so we clean up
	Person_destroy(boris);
	Person_destroy(sian);

	return 0;
}
