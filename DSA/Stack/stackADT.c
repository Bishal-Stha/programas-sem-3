#include<stdio.h>
#define SIZE 10
int STACK[SIZE];
int top = -1;

//Operations
int isEmpty(){
    int val = top==-1 ?1 : 0;
    return val;
}

int isFull(){
    int val = top==(SIZE-1) ?1 : 0;
    return val;
}

void push(int data){
    if(isFull())
    printf("Stack is full, can't push %d\n",data);
    else{
    STACK[++top] = data;
    printf("%d is added to the stack.\n",data);
    }

}

void pop(){
    if(isEmpty())
    printf("Stack is empty, nothing to pop.\n");
    else
        printf("%d is popped.\n",STACK[top--]);
}

int peek(){
    return STACK[top];
}

void display(){
    for(int i=top; i>=0; i--){
        printf("%d\t",STACK[i]);
    }
}

int main(){
    push(10); // 10
    push(30); //30 10
    push(35); // 35 30 10
    pop(); // 30 10
    push(40); // 40 30 10
    printf("%d\n",peek()); // 40
    printf("%d\n",isEmpty()); // 0
    display();// 40 30 20
}