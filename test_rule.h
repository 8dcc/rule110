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
