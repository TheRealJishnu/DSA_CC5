#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -1;
int *q;
int size;
//int counter = 1;

void EnQueue() {
    printf("Enter Data to be Inserted: ");
    int data;
    scanf("%d", &data);
    if(back == size-1) {
        q[0] = data;
        front = 0;
    }
    else {
        q[++front] = data;
    }

}

void DeQueue() {
    if (front == back){
        printf("Queue is Empty");
        return;
    }
    else {
        printf("Item %d is out of the Queue", q[front]);
        
    }
}