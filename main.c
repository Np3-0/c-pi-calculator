//lets see did I implement the Leibnez + bbp correctly, prolly not im incredibly sick -> https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80 / https://en.wikipedia.org/wiki/Bailey%E2%80%93Borwein%E2%80%93Plouffe_formula

#include <stdio.h>
#include <math.h>

double leibnez(int digits) {
	double sum = 0;

	for (int i = 0; i < digits; i++) {
		// for each term, the value is calculated by 1/2i+1, where i = an integer

		double value = 1.0 / (2 * i + 1);

		// every second term needs to be negative
		value *= i % 2 == 0 ? 1 : -1;
		sum += value;
	}

	// the system equals pi/4, so this gets the true value
	return 4 * sum;
}

double bbp(int digits) {
    double sum = 0;
    for (int i = 0; i < digits; i++) {
        sum += (1 / pow(16.0, (double) i)) * (4.0/(8 * i + 1) - (2.0/(8 * i + 4)) - (1.0/(8 * i + 5)) - (1.0/(8 * i + 6)));
    }
    return sum;
}

int main() {
	printf("Leibnez formula to 50 decimal places: %.50f\nBBP algorithm to 50 decimal places: %.50f\n", leibnez(50), bbp(50));
	return 0;
}
