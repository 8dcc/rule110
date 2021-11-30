/*
 * Cellular automaton I made. Now displayed as .pbm
 * https://en.wikipedia.org/wiki/Rule_110
 * https://en.wikipedia.org/wiki/Netpbm
 * https://github.com/r4v10l1
 */

#include <stdio.h>

// Height must be > width
#define HEIGHT 1000
#define WIDTH 999

int calc_rule(int a, int b, int c, int mode);	// Rule conditionals
int calc_array();

int main() {
	int array_len = calc_array();

	char line[array_len];
	char line_aux[array_len];
	
	int rule_results;
	int position = 0;
	
	// Clear the arrays
	for (int n = 0; n <= array_len; n++){
		line[n] = 0;
		line_aux[n] = 0;
	}
	line[1] = 1;

	// Start of the .pbm file
	printf("P1\n"); // Black and white
	printf("# Made with https://github.com/r4v10l1/rule110\n");
	printf("%d %d\n", WIDTH, HEIGHT);

	// Display each line
	for (int y = 1; y <= HEIGHT; y++){	
		for (int x = 1; x <= WIDTH; x++){

			rule_results = calc_rule(line[position], line[position+1], line[position+2], 1);
			putchar(rule_results+48);	

			// Stop printing if the lines are too long
			if (x % 75 == 0) {
				putchar('\n');
			}

			// Write into the aux array instead of the main one while reading
			line_aux[x] = rule_results;
			
			position++;
		}

		// After reading the array, replace the aux with the main one
		for (int n = 0; n <= array_len; n++){
			line[n] = line_aux[n];
		}

		putchar('\n');
		position = 0;
	}
}

int calc_array() {
	if (HEIGHT >= WIDTH) {
		return HEIGHT;
	} else {
		return WIDTH;
	}
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
