/*
 * Cellular automaton I made.
 * https://en.wikipedia.org/wiki/Rule_110
 * https://github.com/r4v10l1
 */


#include <stdio.h>

#define STEPS 200				// Amount of lines
#define FILLCHAR 219			// Character to display 1
#define EMPTYCHAR ' '			// Character to display 0

#define PRINT_ARRAY 1

int calc_rule(int, int, int);			// Rule conditionals
int calc_rule_mirror(int, int, int);	// Rule conditionals mirror
int test_rule(int);						// Debug

int main() {
	//test_rule(1);

	char line[STEPS] = {0, 1};  	// Array for line
	char line2[STEPS] = {0, 1}; 	// Create another array to not overwrite the first one
	int rule_results, change_line;
	int position = 0;
	
	// Clear the arrays
	for (int n = 2; n <= STEPS; n++){
		line[n] = 0;
		line2[n] = 0;
	}

	// Displaying
	for (int line_len = 1; line_len < STEPS; line_len++){  // Each line

		// Print array for debug
		if (PRINT_ARRAY == 0) {
			for (int n = 0; n < STEPS; n++){
				printf("%d ", line[n]);
			}
			printf("\n");
		}
		
		for (int i = 1; i <= line_len; i++){  // Each character
			if (change_line == 1) {
				rule_results = calc_rule_mirror(line[position], line[position+1], line[position+2]);
			} else {
				rule_results = calc_rule_mirror(line2[position], line2[position+1], line2[position+2]);
			}

			if (rule_results == 0) {
				putchar(EMPTYCHAR);
			} else {
				putchar(FILLCHAR);
			}

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
	// Option 0 - Test calc_rule()
	// Option 1 - Test calc_rule_mirror()
	if (option == 0) {
		printf("Testing 000: %d\n", calc_rule(0, 0, 0));
		printf("Testing 001: %d\n", calc_rule(0, 0, 1));
		printf("Testing 010: %d\n", calc_rule(0, 1, 0));
		printf("Testing 011: %d\n", calc_rule(0, 1, 1));
		printf("Testing 100: %d\n", calc_rule(1, 0, 0));
		printf("Testing 101: %d\n", calc_rule(1, 0, 1));
		printf("Testing 110: %d\n", calc_rule(1, 1, 0));
		printf("Testing 111: %d\n", calc_rule(1, 1, 1));	
		printf("Testing 312: %d\n", calc_rule(3, 1, 2));
		printf("----------------\n");
	} else if (option == 1) {
		printf("Testing 000: %d\n", calc_rule_mirror(0, 0, 0));
		printf("Testing 001: %d\n", calc_rule_mirror(0, 0, 1));
		printf("Testing 010: %d\n", calc_rule_mirror(0, 1, 0));
		printf("Testing 011: %d\n", calc_rule_mirror(0, 1, 1));
		printf("Testing 100: %d\n", calc_rule_mirror(1, 0, 0));
		printf("Testing 101: %d\n", calc_rule_mirror(1, 0, 1));
		printf("Testing 110: %d\n", calc_rule_mirror(1, 1, 0));
		printf("Testing 111: %d\n", calc_rule_mirror(1, 1, 1));	
		printf("Testing 312: %d\n", calc_rule_mirror(3, 1, 2));
		printf("----------------\n");
	} else {
		return 1;
	}
}

int calc_rule_mirror(int a, int b, int c) {
	// Made a conditional for each rule so it's more visual
	if (a == 0 && b == 0 && c == 0) {
		return 0;	// 000
	} else if (a == 1 && b == 0 && c == 0) {
		return 1;	// 100
	} else if (a == 0 && b == 1 && c == 0) {
		return 1;	// 010
	} else if (a == 1 && b == 1 && c == 0) {
		return 1;	// 110
	} else if (a == 0 && b == 0 && c == 1) {
		return 0;	// 001
	} else if (a == 1 && b == 0 && c == 1) {
		return 1;	// 101
	} else if (a == 0 && b == 1 && c == 1) {
		return 1;	// 011
	} else if (a == 1 && b == 1 && c == 1) {
		return 0;	// 111
	} else {
		return 2;	// ???
	}
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