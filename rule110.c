/*
 * Cellular automaton I made.
 * https://en.wikipedia.org/wiki/Rule_110
 * https://github.com/r4v10l1
 */

#include <stdio.h>

#define STEPS 60000				// Amount of lines
#define MAX_LINE_LEN 250		// Will jump to the next line if the line is too long

#define FILLCHAR 219			// Character to display 1
#define EMPTYCHAR ' '			// Character to display 0

#define PRINT_ARRAY 1
#define PRINT_DETAILS 0

int calc_rule(int a, int b, int c, int mode);	// Rule conditionals
int test_rule(int);								// Debug

int main() {
	//test_rule(1);

	char line[STEPS+1] = {0, 1};  	// Array for line
	char line2[STEPS+1] = {0, 1}; 	// Create another array to not overwrite the first one
	int rule_results, change_line;
	int position = 0;
	
	// Clear the arrays
	for (int n = 2; n <= STEPS+1; n++){
		line[n] = 0;
		line2[n] = 0;
	}

	// Displaying
	if (PRINT_DETAILS == 0) {
		printf("+------------------------------------+\n");
		printf("| Rule 110 visualization             |\n");
		printf("| https://github.com/r4v10l1/rule110 |\n");
		printf("+------------------------------------+\n");
		printf("| Current settings:                  |\n");
		printf("+---------------+--------------------+\n");
		printf("| STEPS:  %5d | MAX_LINE_LEN: %3d  |\n", STEPS, MAX_LINE_LEN);
		printf("| FILLCHAR: %3d | EMPTYCHAR: %3d     |\n", FILLCHAR, EMPTYCHAR);
		printf("+---------------+--------------------+\n");
		printf("\n");
	}

	// Display each line
	for (int line_len = 1; line_len <= STEPS; line_len++){

		// Print array for debug
		if (PRINT_ARRAY == 0) {
			for (int n = 0; n < STEPS; n++){
				if (change_line == 1) {
					printf("%d ", line[n]);
				} else {
					printf("%d ", line2[n]);
				}
			}
			printf("\n");
		}
		
		for (int i = 1; i <= line_len; i++){  // Each character
			if (change_line == 1) {
				rule_results = calc_rule(line[position], line[position+1], line[position+2], 1);
			} else {
				rule_results = calc_rule(line2[position], line2[position+1], line2[position+2], 1);
			}

			// Skip line checking if MAX_LINE_LEN is 0
			if (MAX_LINE_LEN != 0) {
				// Only print the character if the line is not too long
				if (i <= MAX_LINE_LEN) {
					if (rule_results == 0) {
						putchar(EMPTYCHAR);
					} else {
						putchar(FILLCHAR);
					}
				}
			} else {
				if (rule_results == 0) {
					putchar(EMPTYCHAR);
				} else {
					putchar(FILLCHAR);
				}
			}

			// Switch lines
			if (change_line == 0) {
				line[i] = rule_results;
			} else {
				line2[i] = rule_results;
			}

			position++;
		}

		printf("\n");
		position = 0;

		if (change_line == 0) {
			change_line = 1;
		} else {
			change_line = 0;
		}

	}

	return 0;
}  
  
int test_rule(int option) {
	// Option 0 - Test calc_rule(int, int, int, 0)
	// Option 1 - Test calc_rule(int, int, int, 1)
	printf("Testing 000: %d\n", calc_rule(0, 0, 0, option));
	printf("Testing 001: %d\n", calc_rule(0, 0, 1, option));
	printf("Testing 010: %d\n", calc_rule(0, 1, 0, option));
	printf("Testing 011: %d\n", calc_rule(0, 1, 1, option));
	printf("Testing 100: %d\n", calc_rule(1, 0, 0, option));
	printf("Testing 101: %d\n", calc_rule(1, 0, 1, option));
	printf("Testing 110: %d\n", calc_rule(1, 1, 0, option));
	printf("Testing 111: %d\n", calc_rule(1, 1, 1, option));	
	printf("Testing 312: %d\n", calc_rule(3, 1, 2, option));
	printf("----------------\n");
	return 0;
}

int calc_rule(int a, int b, int c, int mode) {
	// Vanilla rule110 or mirror
	if (mode == 1) {
		int temp = a;
		a = c;
		c = temp;
	}

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
