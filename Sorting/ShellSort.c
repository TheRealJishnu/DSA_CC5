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



    for(int gap=size/2; gap>=1; gap/=2)
    {
        for(int i=gap; i<size; i++)            //SORT
        {
            int key = arr[i];
            int j;
            for(j=i-gap; j>=0 && key<arr[j]; j-= gap)
            {
                arr[j+gap] = arr[j];
            }
            arr[j+gap] = key;
        }
    }

    printf("Shell Sorted Array : \n");
    for(int i=0; i<size; i++)
    {
        printf("%d\t", arr[i]);
    }


    return 0;
}
