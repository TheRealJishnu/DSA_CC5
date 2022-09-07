#include <stdio.h>
#include <stdlib.h>

int front = -1;
int back = -1;
int *q;
int size;


int isFull(){
    if ((back + 1) % size == front) {
        return 1;
    }
    else {
        return 0;
    }
}

void EnQueue() {

    if (isFull()) {
        printf("Queue is Full :( Dequeue to Make Room For More Space\n");
        return;
    }
    else {
        back = (back + 1) % size;
        printf("Enter Data to Be Added In Queue :    ");
        scanf("%d", &q[back]);

        //In Case of First Element Insertion
        if(back == 0 && front == -1) {
            front++;
        }
    }
}

void DeQueue() {
    if (front == -1) {
        printf("Queue is Empty :(   Please Enqueue to Dequeue\n");
        return;
    }
    else {
        printf("Data %d Out Of Queue\n", q[front]);
        if (front == back) {                        //If only One data in Queue
            front = -1;
            back = -1;
        }
        else {
            front = (front + 1) % size;
        }

    }
}

void Display() {
    int i = front;
    printf("Queue: ");
    do {
        printf("%d\t", q[front]);
        i = (i + 1) % size;

    }while (i != ((front + 1) % size));
}

int main() {
    printf("Enter Size of Queue : ");
    scanf("%d", &size);
    q = (int*)malloc(size * sizeof(int));
    char ch = 'y';
    while (ch == 'y') {
        printf("Enter 1 to Enqueue\n");
        printf("Enter 2 to Dequeue\n");
        printf("Enter 3 to Display\n");
        int choice;
        scanf("%d", &choice);
        switch(choice) {
            case 1 : EnQueue(); break;
            case 2 : DeQueue(); break;
            case 3 : Display(); break;
            default : printf("Please Enter A Valid Choice\n"); break;
        }
        printf("Do You Want to Keep Going? ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    }
}
