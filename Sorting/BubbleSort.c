#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Enter Array Size: \n");             //ALLOCATION AND INPUT
    int size;
    scanf("%d", &size);
    int *arr = (int*)malloc(size * sizeof(int));
    printf("Enter Array : \n");
    for(int i=0; i<size; i++)
    {
        scanf("%d", &arr[i]);
    }

    printf("Inputted Array : \n");          //Display Input
    for(int i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }
    printf("\n");

    for(int i=0; i<size -1; i++)            //SORT
    {
        for(int j=0; j<size -i -1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("Bubble Sorted Array : \n");
    for(int i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }


    return 0;
}
