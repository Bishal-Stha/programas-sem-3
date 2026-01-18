#include <stdio.h>
#include <math.h>

// f(x)
float f(float x) {
    return x*x*x - x - 2;
}

// f'(x)
float df(float x) {
    return 3*x*x - 1;
}

int main() {
    float x0, x1, eps, error;
    int iter = 1;

    printf("Enter initial guess: ");
    scanf("%f", &x0);

    printf("Enter allowed error: ");
    scanf("%f", &eps);

    // Table header
    printf("\n%-6s %-12s %-12s %-12s %-12s\n",
           "Iter", "Xn", "f(Xn)", "Xn+1", "Error");
    printf("-----------------------------------------------------------\n");

    do {
        if (df(x0) == 0) {
            printf("Derivative zero. Method fails.\n");
            return 0;
        }

        x1 = x0 - f(x0) / df(x0);
        error = fabs(x1 - x0);

        printf("%-6d %-12.6f %-12.6f %-12.6f %-12.6f\n",
               iter, x0, f(x0), x1, error);

        x0 = x1;
        iter++;

    } while (error > eps);

    printf("\nApprox root = %.6f\n", x1);
    printf("Iterations = %d\n", iter - 1);

    return 0;
}
