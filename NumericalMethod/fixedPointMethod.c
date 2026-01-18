#include <stdio.h>
#include <math.h>

// g(x) such that x = g(x)
float g(float x) {
    return cbrt(x + 2);   // From x^3 - x - 2 = 0
}

int main() {
    float x0, x1, eps, error;
    int iter = 1;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    printf("Enter allowed error: ");
    scanf("%f", &eps);

    // Table header
    printf("\n%-6s %-12s %-12s %-12s\n",
           "Iter", "Xn", "Xn+1", "Error");
    printf("---------------------------------------------\n");

    do {
        x1 = g(x0);
        error = fabs(x1 - x0);

        printf("%-6d %-12.6f %-12.6f %-12.6f\n",
               iter, x0, x1, error);

        x0 = x1;
        iter++;

    } while (error > eps);

    printf("\nApprox root = %.6f\n", x1);
    printf("Iterations = %d\n", iter - 1);

    return 0;
}
