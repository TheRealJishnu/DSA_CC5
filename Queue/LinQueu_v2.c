#include <stdio.h>
#include <stdlib.h>

void enqueue();
void dequeue();
void show();
int *arr;
int Rear = - 1;
int Front = - 1;
int SIZE;


int main()
{
    printf("Enter Size of Linear QUEUE...");
    scanf("%d", &SIZE);
    arr = (int*)malloc(SIZE * sizeof(int));
    char ch = 'y';
    while (ch == 'y')
    {
        printf("1.Enqueue Operation\n");
        printf("2.Dequeue Operation\n");
        printf("3.Display the Queue\n");
        //printf("4.Exit\n");
        printf("Enter your choice of operations : ");
        int choice;
        scanf("\n%d", &choice);
        switch (choice)
        {
            case 1:
                enqueue();
                break;
            case 2:
                dequeue();
                break;
            case 3:
                show();
                break;
            // case 4:
            // exit(0);
            default:
            printf("Incorrect choice \n");
            break;
        }
        printf("Do You Want to Keep Going? ");
        scanf("%c", &ch);
        scanf("%c", &ch);
    } 
} 
 
void enqueue()
{
    int insert_item;
    if (Rear == SIZE - 1)
       printf("Overflow \n");
    else
    {
        if (Front == - 1)
        Front = 0;
        printf("Element to be inserted in the Queue : ");
        scanf("%d", &insert_item);
        Rear = Rear + 1;
        arr[Rear] = insert_item;
    }
} 
 
void dequeue()
{
    if (Front == - 1 || Front > Rear)
    {
        printf("Underflow \n");
        return ;
    }
    else
    {
        printf("Element deleted from the Queue: %d\n", arr[Front]);
        Front = Front + 1;
    }
} 
 
void show()
{
    
    if (Front == - 1)
        printf("Empty Queue \n");
    else
    {
        printf("Queue: \n");
        for (int i = Front; i <= Rear; i++)
            printf("%d ", arr[i]);
        printf("\n");
    }
} 
