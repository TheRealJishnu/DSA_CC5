#include <stdio.h>
#include <stdlib.h>

int *arr;
int length;
int search;
int flag = 0;

int BinarySearchArr(int low, int high) {
    if(low <= high){
            int mid = (high + low)/2;
        
        if(search == arr[mid]){
            flag = 1;
            return mid;
        }
        else if (search < arr[mid]){
            high = mid - 1;
            return BinarySearchArr(low, high);
        }
        else if (search > arr[mid]){
            low = mid + 1;
            return BinarySearchArr(low, high);
        }
    }
    return -1;



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
