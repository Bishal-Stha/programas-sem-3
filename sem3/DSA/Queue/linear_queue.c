#include<stdio.h>
#define SIZE 10
int QUEUE[SIZE];
int front = -1, rear= -1;

int isEmpty(){
    // int value = (rear== -1 || rear == front) ?  1 : 0;
    // int value = (rear== -1) ?  1 : 0;
    // return value;
    return (front == -1 || front > rear);

}

int isFull(){
    // int val = (rear==SIZE-1) ? 1:0;
    // return val;
    return (rear == SIZE-1);
}

void enqueue(int data){
    // add the value from the rear part.
    if(isFull())
    printf("Queue is full.\n");
    else {
    if(front == -1)
    front = 0;
    QUEUE[++rear] = data;
    printf("%d is added to the queue.\n",data);
    }
}

void dequeue(){
    if(isEmpty())
    printf("Queue is empty nothing to dequeue.\n");
    else {
        printf("%d is dequeued.\n",QUEUE[front++]);
        if(front > rear){
        front = -1;
        rear = -1;
        }
    }
}

int peek(){
    if(isEmpty()){
        printf("Queue is empty\n");
        return -1;
    }
    return QUEUE[front];
}

void display(){
    if(isEmpty())
    printf("Queue is empty");

    printf("Displaying Queue:\n");
    for(int i=front; i<=rear; i++){
        printf("%d\t",QUEUE[i]);
    }
    printf("\n");
}

/*
1, 2, 3, 4
front = -1, rear = -1
enqueue(1) => front = -1, rear = 0
enqueue(2) => front = -1, rear = 1
enqueue(3) => front = -1, rear = 2
enqueue(4) => front = -1, rear = 3
display() =>
i =0 ; i < rear; i++  that means i=0 to i <= rear
 at i=0, QUEUE[i] = 1
 at i=1, QUEUE[i] = 2
 at i=2, QUEUE[i] = 3
 at i=3, QUEUE[i] = 4
 at i=4, breaks the loop.
*/

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    enqueue(4);
    display();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    dequeue();
    printf("%d \t %d\t",front, rear);
}