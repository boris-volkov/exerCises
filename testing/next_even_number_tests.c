#include <assert.h>

#include "declarations.h"

void TESTCASE_correct_returns()
{
	assert(next_even_number() == 0);
	assert(next_even_number() == 2);
	assert(next_even_number() == 4);
	assert(next_even_number() == 6);
	assert(next_even_number() == 8);
}

void TESTCASE_correct_rotation() 
{
	int64_t number = next_even_number();
	next_even_number();
	next_even_number();
	next_even_number();
	next_even_number();
	int64_t number2 = next_even_number();
	assert(number == number2);
}

