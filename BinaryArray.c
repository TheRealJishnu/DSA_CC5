#include <stdio.h>
#include <stdlib.h>

int *arr;
int length;
int search;
int flag = 0;

int BinarySearchArr(int low, int high) {
    int mid = (high + low)/2;

    if(low == high) {
        return - 1;
    }
    if(search == arr[mid]){
        flag = 1;
        return mid;
    }
    else if (search < arr[mid]){
        high = mid;
        BinarySearchArr(low, high);
    }
    else if (search > arr[mid]){
        low = mid;
        BinarySearchArr(low, high);
    }
    
    

}

int main() {
    printf("Enter Length of Array");
    scanf("%d", &length);
    arr = (int*)malloc(length * sizeof(int));
    printf("Enter Array : ");
    for (int i = 0; i < length; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("Enter Element to Search: ");
    scanf("%d", &search);
    printf("\nSearched Element is in Position: %d", BinarySearchArr(0, length - 1));


    
}

