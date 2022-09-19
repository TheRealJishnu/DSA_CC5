#include <stdio.h>
#include <stdlib.h>

typedef struct DoubleLinkeed {
    int data;
    struct DoubleLinkeed *previous;
    struct DoubleLinkeed *next;
} dnode;

dnode *head = NULL;
dnode *tail = NULL;

void show(){
    dnode *temp = head;
    if(temp == NULL) {
        printf("The Linked List is Currently Empty :) ");
        return;
    }
    else {
        while (temp != NULL)
        {
            printf("%d\t", temp->data);
            temp = temp->next;
        }
    }
}

int getLength(){
    dnode *temp = head;
    int counter = 0;
    while(temp != NULL) {
        temp = temp->next;
        counter++;
    }
    return counter;
}

void Add_at_Start() {
    dnode *temp = (dnode*)malloc(sizeof(dnode));
    printf("Enter Data to be Added at First : ");
    scanf("%d", &temp->data);
    if (head == NULL){
        head = temp;
        tail = temp;
        temp->next = NULL;
        temp->previous = NULL;
    }
    else {
        temp->next = head;
        head->previous = temp;
        head = temp;
    }
}

void Add_at_End() {
    dnode *temp = (dnode*)malloc(sizeof(dnode));
    printf("Enter Data to be Added at Last : ");
    scanf("%d", &temp->data);
    if (head == NULL){
        head = temp;
        tail = temp;
        temp->next = NULL;
        temp->previous = NULL;
    }
    else {
        tail->next = temp;
        temp->previous = tail;
        tail = temp;
        temp->next = NULL;
    }
}

void Add_after_Position_n() {
    dnode *temp;
    printf("Enter The Position After Whichyou are Inputting Data: ");
    int pos;
    scanf("%d", &pos);
    if(pos == 0){
        Add_at_Start();
    }
    else if(pos > getLength()){
        printf("Position Number is More than Linked List Length");
        return;
    }
    else if(pos == getLength()){
        Add_at_End();
    }
    else{
        printf("Enter Data to Be Added after Position %d : ", pos);
        scanf("%d", &temp->data);
        dnode *ttm = head;
        int counter = 1;
        while(ttm != NULL && counter < pos ) {
            ttm = ttm->next;
        }
        temp->next = ttm->next;
        temp->previous = ttm->next->previous;
        ttm->next = temp;
        temp->next->previous = temp;
    }
}

void Add_at_Position_n(){
    dnode *temp;
    printf("Enter The Position After Whichyou are Inputting Data: ");
    int pos;
    scanf("%d", &pos);
    if(pos == 1){
        Add_at_Start();
    }
    else if(pos > getLength()){
        printf("Position Number is More than Linked List Length");
    }
    else if(pos == getLength()+1){
        Add_at_End();
    }
    // else if(pos == getLength()){
    //     Add_at_End();
    // }
    else{
        dnode *ttm = head;
        int counter = 1;
        while (ttm != NULL && counter <= pos-2){
            ttm = ttm->next;
        }
        temp->next = ttm->next;
    }
}

void Delete_First_dnode() {
    if (head == NULL) {
        printf("No Node to Delete ");
        return;
    }
    else {
        head = head->next;
        free(head->previous);
        head->previous = NULL;
        if (getLength() == 1)
            tail->previous = NULL;
    }
}

void Delete_Last_dnode() {
    if (head == NULL) {
        printf("No Node to Delete ");
    }
    else{
        tail = tail->previous;
        free(tail->next);
        tail->next = NULL;
        if (getLength() == 1)
            tail->next = NULL;
    }
}

void ReverseList (){
    dnode *temp = head;
    for(int i = 1; i <= getLength(); i++) {
        dnode *ttm;
        ttm = temp->next;
        ttm->next = ttm->previous;
        ttm->previous = ttm;

        ttm = ttm->previous;
    }
    temp = head;
    head = tail;
    tail = temp;
}

void Swap(dnode *s1, dnode *s2) {
    int temp = s1->data;
    s1->data = s2->data;
    s2->data = temp;
}

void BubbleSort() {
    
    for (int i = 0; i < getLength()-1; i++){
        dnode *temp1 = head;
        dnode *temp2 = head->next;

        for (int j = 0; j < getLength()-1-i; j++){
            if(temp1->data > temp2->data)
                Swap(temp1, temp2);
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
        
    }
    
}



int main()
{
    
    char ch='y';

    while(ch=='y')
    {
        printf("Enter 1 To Show Linked List\nEnter 2 to Enter Data at First\n");
        printf("Enter 3 To Add Data At The End\nEnter 4 to Enter Data At a Position\n");
        printf("Enter 5 To Bubble Sort\n");
        int choice;
        scanf("%d", &choice);
        switch (choice) {
            case 1 : show(); break;
            case 2 : Add_at_Start(); break;
            case 3 : Add_at_End(); break;
            case 4 : Add_at_Position_n(); break;
            case 5 : BubbleSort(); break;
            default: printf("Enter Valid Input");
        }
      printf("\nDo you want to continue...: \n");
      scanf("%c",&ch);
      scanf("%c",&ch);
    }
}
