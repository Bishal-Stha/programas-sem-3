#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

int stack[MAX];
int top = -1;

/* Stack operations */
void push(int x) {
    stack[++top] = x;
}

int pop() {
    return stack[top--];
}

int main() {
    char prefix[MAX];
    int i, A, B, result;

    printf("Enter prefix expression: ");
    scanf("%s", prefix);

    /* Scan from right to left */
    for (i = strlen(prefix) - 1; i >= 0; i--) {

        if (isdigit(prefix[i])) {
            push(prefix[i] - '0');
        } else {
            A = pop();
            B = pop();

            switch (prefix[i]) {
                case '+': result = A + B; break;
                case '-': result = A - B; break;
                case '*': result = A * B; break;
                case '/': result = A / B; break;
            }

            push(result);
        }
    }

    printf("Result = %d\n", pop());
    return 0;
}
