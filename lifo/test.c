#include <stdio.h>

#include "headers/lifo.h"
#include "lifo-test/lifo.test.h"
#include "lifo-test/color.h"

void printTestResult(int testReturn, char *msg, int *counter);
void printTestConclusion(int nb_test, int nb_test_success);

int main(void) {
	int nb_test = 1;
	int nb_test_success = 0;
	int returned_value;

	returned_value = lifo_test_with_not_init_lifo();
	printTestResult(returned_value, "LIFO NOT INIT", &nb_test_success);

	/* write the conclusion */
	printTestConclusion(nb_test, nb_test_success);

	return 0;
}

/**
 * printTestResult write if a test succed or failed with adding
 * one at the counter if succed
 * 
 * @param testReturn value of the test
 * @param msg little message to discribe the test
 * @param counter number of success test
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void printTestResult(int testReturn, char *msg, int *counter) {
	testReturn
		? printf("%sTest %s failed%s\n", RED, msg, DEFAULT_COLOR)
		: printf("%sTest %s success%s\n", GREEN, msg, DEFAULT_COLOR)
	;

	(*counter) += testReturn ? 0 : 1;
}

/**
 * printTestConclusion write de pourcentage of test success
 * 
 * @param nb_test total of test executed
 * @param nb_test_success number of test succed
 * 
 * @author Yanis GENY
 * @version 1.0
 */
void printTestConclusion(int nb_test, int nb_test_success) {
	float success_pourcentage = (float)nb_test_success / (float)nb_test * 100;

	success_pourcentage >= 85.0
		? printf("\n%s%.02f%c%s test success\n", GREEN, success_pourcentage, '%', DEFAULT_COLOR)
		: success_pourcentage >= 50.0
			? printf("\n%s%.02f%c%s test success\n", YELLOW, success_pourcentage, '%', DEFAULT_COLOR)
			: printf("\n%s%.02f%c%s test success\n", RED, success_pourcentage, '%', DEFAULT_COLOR)
	;
}
