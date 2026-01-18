#include <stdio.h>
#include <math.h>

// Define the function f(x)
float f(float x) {
    return x*x*x - x - 2;   // Example: x^3 - x - 2
}

int main() {
    float a, b, mid, eps;
    int iteration = 0;

    // Input initial guesses
    printf("Enter a and b: ");
    scanf("%f %f", &a, &b);

    // Check validity
    if (f(a) * f(b) >= 0) {
        printf("Invalid interval. f(a) and f(b) must have opposite signs.\n");
        return 0;
    }

    printf("Enter allowed error: ");
    scanf("%f", &eps);

    // Bisection loop
    do {
        mid = (a + b) / 2;
        iteration++;

        if (f(a) * f(mid) < 0)
            b = mid;
        else
            a = mid;

    } while (fabs(f(mid)) > eps);

    // Output result
    printf("Root = %.5f\n", mid);
    printf("Iterations = %d\n", iteration);

    return 0;
}
