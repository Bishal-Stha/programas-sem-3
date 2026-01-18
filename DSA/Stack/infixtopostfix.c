// Infix to Postfix Conversion
//A + B - (C*D/E)
#include<stdio.h>
#include<ctype.h>

#define MAX 20

char stack[MAX];
int top = -1;

void push(char x){
	stack[++top] = x;
}
char pop(){
	if(top == -1)
		return -1;
	else
		return stack[top--];
}

int priority(char x){
	if(x == '(')
		return 0;
	if(x == '+' || x == '-')
		return 1;
	if(x == '*' || x == '/')
		return 2;
	if(x == '^')
		return 3;
}

int main()
{
	char infix[MAX], postfix[MAX];
	int i, k = 0;
	char x;
	
	printf("Enter infix expression:");
	scanf("%s", infix);     //A+B-(C*D/E)\0  //5+2-
	
	for(i=0;infix[i] != '\0';i++){   //i = 2
		if(isalnum(infix[i]))
			postfix[k++] = infix[i];
			
		else if(infix[i] == '(')
			push(infix[i]);
			
		else if(infix[i] == ')'){
			while((x = pop()) != '(')
				postfix[k++] = x;
		}
		else{
			while(top != -1 && priority(stack[top]) >= priority(infix[i])){     //infix[i] = -, i = 3
				postfix[k++] = pop();
		}		
			push(infix[i]);
	}		
	}
	while(top != -1){
		postfix[k++] = pop();
	}
	postfix[k] = '\0';
	
	printf("Postfix Expression = %s",postfix);
	return 0;
}