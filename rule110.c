/*
 * Cellular automaton I made.
 * https://en.wikipedia.org/wiki/Rule_110
 * https://github.com/r4v10l1
 */


// TODO: Fix broky thing with array?

#include <stdio.h>

#define STEPS 20			// Amount of lines
#define MAX_LINE_LENGTH 20		// Width of the thing

int calc_rule(int, int, int);	// Rule conditionals
int test_rule();				// Debug

main() {
	//test_rule();

	char line[MAX_LINE_LENGTH];
	int position = 0, line_len = 1;
	
	// Clear the array
	for (int n = 0; n <= MAX_LINE_LENGTH; n++){
		line[n] = 1;
	}

	// Thing
	for (int n = 0; n < STEPS; n++){
		for (int i = 1; i <= line_len; i++){ // line[0] is always 1
			if (calc_rule(line[position], line[position+1], line[position+2]) == 0) {
				printf(" ");
				line[i] = 0;
			} else {
				printf("#");
				line[i] = 1;
			}
			position++;
		}
		printf("\n");
		line_len++;
	}

	return 0;
}

int test_rule() {
	printf("Testing 000: %d\n", calc_rule(0, 0, 0));
	printf("Testing 001: %d\n", calc_rule(0, 0, 1));
	printf("Testing 010: %d\n", calc_rule(0, 1, 0));
	printf("Testing 011: %d\n", calc_rule(0, 1, 1));
	printf("Testing 100: %d\n", calc_rule(1, 0, 0));
	printf("Testing 101: %d\n", calc_rule(1, 0, 1));
	printf("Testing 110: %d\n", calc_rule(1, 1, 0));
	printf("Testing 111: %d\n", calc_rule(1, 1, 1));
}

int calc_rule(int a, int b, int c) {
	// Made a conditional for each rule so it's more visual
	if (a == 0 && b == 0 && c == 0) {
		return 0;	// 000
	} else if (a == 0 && b == 0 && c == 1) {
		return 1;	// 001
	} else if (a == 0 && b == 1 && c == 0) {
		return 1;	// 010
	} else if (a == 0 && b == 1 && c == 1) {
		return 1;	// 011
	} else if (a == 1 && b == 0 && c == 0) {
		return 0;	// 100
	} else if (a == 1 && b == 0 && c == 1) {
		return 1;	// 101
	} else if (a == 1 && b == 1 && c == 0) {
		return 1;	// 110
	} else if (a == 1 && b == 1 && c == 1) {
		return 0;	// 111
	} else {
		return 2;	// ???
	}
}
