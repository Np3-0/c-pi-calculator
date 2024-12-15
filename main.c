//lets see did I implement the Leibnez + machin-like formula correctly, prolly not im incredibly sick -> https://en.wikipedia.org/wiki/Leibniz_formula_for_%CF%80 / https://en.wikipedia.org/wiki/Machin-like_formula

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

double machin() {
    // multply by 4 for same reason as prior, real equation is pi/4 = 4arctan1/5 - arctan1/239
    return 4 * (4 * atan(1.0 / 5) - atan(1.0 / 239));
}

int main() {
    printf("Leibnez formula to 50 decimal places: %.50f\nMachin-Like formula to 50 decimal places: %.50f\n", leibnez(50), machin());
    return 0;
}
