#include <stdio.h>
#include <stdlib.h>

int *arr;
int front, back;

int main()
{
    printf("Enter Size of Deque");
    int size;
    scanf("%d", &size);
    arr = (int*)malloc(sizeof(int) * size);
    front = -1;
    back = -1;
    return 0;
}

int isFull()
{
    int check = (back + 1) % size;
    if(check == front)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void Insert_at_First()
{
    if(!isFull())
    {
        if(front == -1)
        {
            int data;
            printf("Enter Data to be Added at First : ");
            scanf("%d", &data);
            arr[++back] = data;
        }
    }
    else
    {
        printf("Deque is Full");
        return;
    }
}
