#include <stdio.h>
#include <stdlib.h>

typedef struct CircularLinkedList {
    int data;
    struct CircularLinkedList *next;
} node;

node *head = NULL;
node *last = NULL;


int getLength() {
    node *temp = head;
    int count = 0;
    if (head == NULL) {
        return 0;
    }
    else {
        while (temp != last) {
        count++;
        temp = temp->next;
    }
    return ++count;
    }
}
void show() {
    node *temp = head;
     do{
        printf("%d\t", temp->data);
        temp = temp->next;
    }while (temp!= head);
}

void Insert_At_Start() {
    node *temp = (node*)malloc(sizeof(node));
    printf("Enter Data to be Added At First Position: ");
    scanf("%d", &temp->data);
    if (head == NULL) {
        head = temp;
        temp -> next = head;
        last = head;
    }
    else {
        temp->next = head;
        head = temp;
        last->next = head;
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

void Delete_First() {
    last -> next = head -> next;
    free(head);
    head = last -> next;
    if (head == last) {
        head = NULL;
        last = NULL;
    }
}

void Delete_Last() {
    node *ttm = head;
    while (ttm->next != last) {
        ttm = ttm->next;
    }
    free(last);
    ttm->next = head;
    last = ttm;

    if (head == last) {
        head = NULL;
        last = NULL;
    }
}

int main() {
    printf("\nEnter 1 to Add Data At Start \nEnter 2 to Add Data At End");
    printf("\nEnter 3 to Delete Data At Start \nEnter 4 to Delete Data At End");
    printf("\nEnter 5 to Show Data \n");
    char c = 'y';

    while (c == 'y'){
        int choice;
        printf("Enter Choice:   ");
        scanf("%d", &choice);
        switch (choice) {
            case 5: show(); break;
            case 1: Insert_At_Start(); break;
            case 2: Insert_At_End(); break;
            case 3: Delete_First(); break;
            case 4: Delete_Last(); break;
            
            default : printf("You Did Not Enter Valid Choice    :)\n");
        }
        printf("Do You Want to Continue?\t");
        scanf("%c", &c);
        scanf("%c", &c);
    }
}