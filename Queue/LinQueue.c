#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -1;
int *q;
int counter = 1;

void EnQueue() {
    
    printf("Enter Data to be Inserted: ");
    if (front = -1 ) {
        scanf("%d", &q[++front]);
    }
    ++counter;
}

void display() {
    if (front <= back) {
        for (int i = front; i<=back; i++) {
            printf("%d\t", q[i]);
        }
    }
    else {
        printf("Queue is Empty");
        return;
    }
}

void DeQueue() {
    if(front < back) {} 
}

int main() {
    //Initialise and Memory Allocation
    printf("Enter Size of Queue");
    int size;
    scanf("%d", &size);
    q = (int*)malloc(size * sizeof(int));


}
