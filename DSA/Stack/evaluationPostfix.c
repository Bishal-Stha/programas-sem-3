#include <stdio.h>
#include <ctype.h>

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
    char postfix[MAX];
    int i, A, B, result;

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    for (i = 0; postfix[i] != '\0'; i++) {

        /* If operand, push to stack */
        if (isdigit(postfix[i])) {
            push(postfix[i] - '0');
        }
        /* If operator, pop two operands */
        else {
            B = pop();
            A = pop();

            switch (postfix[i]) {
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
