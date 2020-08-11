#include <stdio.h>


void TESTCASE_calc_factorial__fact_of_zero_is_one();

void TESTCASE_calc_factorial__fact_of_negative_is_one();

void TESTCASE_calc_factorial__fact_of_5_is_120();

void TESTCASE_correct_returns();

void TESTCASE_correct_rotation();

int main() {
	TESTCASE_calc_factorial__fact_of_zero_is_one();
	TESTCASE_calc_factorial__fact_of_negative_is_one();
	TESTCASE_calc_factorial__fact_of_5_is_120();
	TESTCASE_correct_returns();
	TESTCASE_correct_rotation();
	fprintf(stdout, "All tests run successfully");
	return 0;
}

