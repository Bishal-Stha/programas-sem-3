#include <stdio.h>
#include <math.h>

// Define the function f(x)
float f(float x) {
    return x*x*x - x - 2;   // Example: x^3 - x - 2
}

int main() {
    float x0, x1, x2, eps;
    int iteration = 0;

    // Input initial guesses
    printf("Enter initial guesses x0 and x1: ");
    scanf("%f %f", &x0, &x1);

    printf("Enter allowed error: ");
    scanf("%f", &eps);

    // Secant method loop
    do {
        if (f(x1) - f(x0) == 0) {
            printf("Division by zero error.\n");
            return 0;
        }

        x2 = x1 - (f(x1) * (x1 - x0)) / (f(x1) - f(x0));

        x0 = x1;
        x1 = x2;
        iteration++;

    } while (fabs(f(x2)) > eps);

    // Output result
    printf("Root = %.5f\n", x2);
    printf("Iterations = %d\n", iteration);

    return 0;
}
