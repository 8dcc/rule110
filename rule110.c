/*
 * Cellular automaton I made.
 * https://en.wikipedia.org/wiki/Rule_110
 * https://github.com/r4v10l1
 */

#include <stdio.h>

#define STEPS 60000			// Amount of lines. Will be infinite if 0
#define MAX_LINE_LEN 200		// Max length of the lines so they don't overflow

#define FILLCHAR 219			// Character to display 1
#define EMPTYCHAR ' '			// Character to display 0

#define PRINT_DETAILS 1			// If 1 will print details about the current simulation

int calc_rule(int a, int b, int c, int mode);		// Rule conditionals
void print_line(int line_array[], int line_len);	// For printing the array to the console

int main() {
    // We need to make it same as SPTEPS because it grows proportionally in width
    int array_size = 10000;
    if (STEPS) array_size = STEPS;

    int line[array_size], line_buffer[array_size];
    int rule_results;

    // Set the values here so it doesn't throw an error
    line[0] = 0;
    line[1] = 1;

    // Clear the arrays
    for (int n = 2; n <= array_size; n++){
        line[n] = 0;
        line_buffer[n] = 0;
    }

    // Displaying
    if (PRINT_DETAILS) {
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

    for (int line_n = 1; line_n <= STEPS || STEPS == 0; line_n++){		// Each line
        for (int char_pos = 1; char_pos <= line_n; char_pos++){		// Each character to be printed
            // The loop needs to start with 1 because we subtract one,
            // and the '-1' is 0 (see array declaration)
            rule_results = calc_rule(line[char_pos-1], line[char_pos], line[char_pos+1], 1);
            line_buffer[char_pos] = rule_results;
        }

        // Move buffer to original array
        for (int n = 0; n < array_size; n++) {
            line[n] = line_buffer[n];
        }

        print_line(line, line_n);
    }

    return 0;
}

void print_line(int line[], int line_len) {
    for (int char_pos = 1; char_pos <= line_len; char_pos++){	// Each character to be printed
        if (MAX_LINE_LEN && char_pos <= MAX_LINE_LEN) {		// Skip line checking if MAX_LINE_LEN is 0
            if (line[char_pos]) putchar(EMPTYCHAR);
            else putchar(FILLCHAR);
        } else {
            if (line[char_pos]) putchar(EMPTYCHAR);
            else putchar(FILLCHAR);
        }
    }
    printf("\n");
}

int calc_rule(int a, int b, int c, int mode) {
    // Vanilla rule110 or mirror
    if (mode == 1) {
        int temp = a;
        a = c;
        c = temp;
    }

    // Made a conditional for each rule so it's more visual
    if (a == 0 && b == 0 && c == 0)         return 0;	// 000
    else if (a == 0 && b == 0 && c == 1)    return 1;	// 001
    else if (a == 0 && b == 1 && c == 0)    return 1;	// 010
    else if (a == 0 && b == 1 && c == 1)    return 1;	// 011
    else if (a == 1 && b == 0 && c == 0)    return 0;	// 100
    else if (a == 1 && b == 0 && c == 1)    return 1;	// 101
    else if (a == 1 && b == 1 && c == 0)    return 1;	// 110
    else if (a == 1 && b == 1 && c == 1)    return 0;	// 111
    else                                    return 2;	// ???
}
