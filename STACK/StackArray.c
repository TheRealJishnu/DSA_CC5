#include <stdio.h>
#include <stdlib.h>

void pop();
void push();

int tos = -1;
int max_lim;

typedef struct Stack {
    int data;
} stack;

stack *stack1;

void pop(){
    if (tos == -1) {
        printf("Stack Underflow\t\t ↓↓↓↓↓\n");
        return;
    }
    else {
        printf("Data at Position %d :\t%d\n", (tos+1), stack1[tos--].data);    //--
    }
}

void push(){
    if (tos == max_lim -1){
        printf("Stack Overflow\t\t ↑↑↑↑↑\n");
        return;
    }
    else {
        printf("Enter Data to Be Added in Stack\t:\t");
        int data;
        scanf("%d", &data);
        stack1[++tos].data = data;
    }
}

void peek(){
    if(tos == -1) {
        printf("Stack is Empty  :(\n");
        return;
    }
    else {
        printf("Data At Position %d : %d\n", (tos+1), stack1[tos].data);
    }
}

void display() {
    for (int i = 0; i < max_lim; i++)
    {
        printf("%d \t", stack1[i]);
    }
    printf("\n");
    
}

int main() {
    printf("Enter Size of Stack\t:\t");
    scanf("%d", &max_lim);
    stack1 = (stack*)malloc(max_lim * sizeof(stack));
    char ch;
    do {
        int choice;
    printf("\nEnter 1 for Push\nEnter 2 for Pop\n");
    printf("Enter 3 for Peek\nEnter 4 for Display\n\nChoice:\t");
    scanf("%d", &choice);
    switch(choice) {
        case 1 : push(); break;
        case 2 : pop(); break;
        case 3 : peek(); break;
        case 4 : display(); break;
        default : printf("Invalid Choice\t:(\n"); break;
    }
    printf("Do you want to Continue? (y/n) / (Y/N):\t");
    scanf("%c", &ch);
    scanf("%c", &ch);

    } while (ch == 'Y' || ch == 'y');

    
}
