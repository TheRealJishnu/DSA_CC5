#include <stdio.h>
#include <stdlib.h>

int *arr;
int n;

int main()
{
    int size;
    printf("Enter Size : ");
    scanf("%d", &n);
    arr = (int*)malloc(n * (sizeof(int)));

    printf("Enter Data : ");        //DATA INPUT
    for(int i=0; i<n; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("\nInput: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }

    SelectionSort();

    printf("\nOutput: ");
    for(int i=0; i<n; i++)
    {
        printf("%d\t", arr[i]);
    }
    return 0;
}

void SelectionSort()
{
    for(int i=0; i<n; i++)
    {
        int k;
        int min = arr[i];
        for(int j=i+1; j<n; j++)  //Find Smallest Element
        {
            if(min > arr[j])
            {
                min = arr[j];
                k = j;
            }
        }

        if(min < arr[i])            //Check And Swap
        {
            int temp = arr[k];
            arr[k] = arr[i];
            arr[i] = temp;
        }
    }
}
