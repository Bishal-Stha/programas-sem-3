/*
A+B-C*(D-E/F+G)^H
*/

#include<stdio.h>
#define SIZE 20
char STACK[SIZE];
int top = -1;
char infix[20];
char prefix[20];

int precedence(char c){
    if(c == '(') return 0;
    else if(c == '+' || c== '-') return 1;
    else if(c == '*' || c== '/') return 2;
    else return 3;
}

void push(char ch){
    if(top != SIZE-1)
    STACK[++top] = ch;
}

char pop(){
    if(top != -1)
    return STACK[top--];
}

char peek(){
    return STACK[top];
}

void infix2Prefix(char infix[], char prefix[]){

}