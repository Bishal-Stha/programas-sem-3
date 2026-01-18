#include <stdio.h>
#include <string.h>
#include <ctype.h>

char stack[100];
int top = -1;

/* Push */
void push(char c) {
    stack[++top] = c;
}

/* Pop */
char pop() {
    return stack[top--];
}

/* Operator priority */
int priority(char c) {
    if (c == '+' || c == '-') return 1;
    if (c == '*' || c == '/') return 2;
    if (c == '^') return 3;
    return 0;
}

/* Reverse string */
void reverse(char exp[]) {
    int i, j;
    char temp;
    for (i = 0, j = strlen(exp) - 1; i < j; i++, j--) {
        temp = exp[i];
        exp[i] = exp[j];
        exp[j] = temp;
    }
}

int main() {
    char infix[100], prefix[100];
    int i, k = 0;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    /* Step 1: Reverse infix */
    reverse(infix);

    /* Step 2: Replace brackets */
    for (i = 0; infix[i] != '\0'; i++) {
        if (infix[i] == '(')
            infix[i] = ')';
        else if (infix[i] == ')')
            infix[i] = '(';
    }

    /* Step 3: Infix to Postfix (with correct associativity) */
    for (i = 0; infix[i] != '\0'; i++) {

        /* Operand */
        if (isalnum(infix[i])) {
            prefix[k++] = infix[i];
        }

        /* Left bracket */
        else if (infix[i] == '(') {
            push(infix[i]);
        }

        /* Right bracket */
        else if (infix[i] == ')') {
            while (top != -1 && stack[top] != '(')
                prefix[k++] = pop();
            pop(); // remove '('
        }

        /* Operator */
        else {
            while (top != -1 &&
                   priority(stack[top]) > priority(infix[i])) {
                prefix[k++] = pop();
            }
            push(infix[i]);
        }
    }

    /* Pop remaining operators */
    while (top != -1)
        prefix[k++] = pop();

    prefix[k] = '\0';

    /* Step 4: Reverse postfix to get prefix */
    reverse(prefix);

    printf("Prefix expression: %s\n", prefix);

    return 0;
}
