#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkedList {
    int data;
    struct CircularLinkedList *next;
} node;

node *head = NULL;
node *last = NULL;

void show() {
    node *temp = head;
    while (temp->next != head) {
        printf("%d\t", temp->data);
        temp = temp->next;
    }
}

void Insert_At_Start() {
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter Data to be Added At First Position: ");
    scanf("%d", &temp->data);
    if (head == NULL) {
        head = temp;
        last = temp;
    }
    else {
        temp->next = head;
        last->next = temp;
        head = temp;
    }
}

void Insert_At_End() {
    node *temp = (node*)malloc(sizeof(node));
    if (head == NULL) {
        head = temp;
        last = temp;
    }
    else {
        last->next = temp;
        temp->next = head;
        head = temp;
    }
}
