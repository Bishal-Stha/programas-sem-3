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
    if(isEmpty()){
        printf("Stack is empty");
    return -1;
    }
    return STACK[top];
}

void display(){
    for(int i=top; i>=0; i--){
        printf("%d\t",STACK[i]);
    }
}

int main(){
    char val;
    int data;
    do
    {
        printf("\n");
        printf("1. Push()\n");
        printf("2. Pop()\n");
        printf("3. Peek()\n");
        printf("4. isEmpty()\n");
        printf("5. isFull()\n");
        printf("6. Display()\n");
        printf("0. exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &val);

        switch(val){
            case '0': return 0;
            
            case '1': {
                printf("Enter element value: ");
                scanf("%d",&data);
                push(data);
                break;
            }
            case '2': pop();
            break;

            case '3': {
                if(peek()==-1)
                printf("Stack is empty\n");
                printf("Top element in stack: %d\n",peek());
                break;
            }

            case '4': {
        
                if(isEmpty())
                  printf("Stack is empty");
                printf("Stack is not empty");
            break;
            }

            case '5': {
        
                if(isFull())
                 printf("Stack is Full");
                printf("Stack is not full");
            break;
            }

            case '6': display();
            break;

            default: printf("Invalid input\n");
            break;

        }
    } while (val != '0');
    
}