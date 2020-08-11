#include <assert.h>

#include "declarations.h"

int64_t input_value = -1;

int64_t feed_stub() {
	return input_value;
}
// feed stub function follows the same contract 
// that the factorial function expects as input, 
// except here we can control the value that it 
// returns. This is a way to test the factorial 
// function in isolation from the other generator
// function that it depends on.

void TESTCASE_calc_factorial__fact_of_zero_is_one() 
{
	input_value = 0;
	int64_t fact = calc_factorial(feed_stub);
	assert(fact == 1);
}

void TESTCASE_calc_factorial__fact_of_negative_is_one()
{
	input_value = -10;
	int64_t fact = calc_factorial(feed_stub);
	assert(fact == 1);
}

void TESTCASE_calc_factorial__fact_of_5_is_120() {
	input_value = 5;
	int64_t fact = calc_factorial(feed_stub);
	assert(fact == 120);
}



