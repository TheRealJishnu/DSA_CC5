#include <bits/stdc++.h>

using namespace std;

#define ll long long

void Swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int* Selection_Sort(int* arr, ll n)
{
    ll min, i, j;
    for(i=0; i<n; i++)
    {
        //FIND MINIMUM INDEX AND SWAP
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j] < arr[min])
            {
                min = j;
            }
        }
        Swap(&arr[min], &arr[i]);
    }

    return arr;

}




int main()
{
    ll n;
    cout << "Enter Size : " ;
    cin >> n;
    int *arr = (int*)malloc(n * sizeof(int));
    cout << "Enter Elements-" << endl;
    for(ll i=0; i<n; i++) cin >> arr[i];
    cout << "Unsorted : ";
    for(ll i=0; i<n; i++) cout << arr[i] << " ";
    cout << endl;


    arr = Selection_Sort(arr, n);
    cout << "Sorted : " << endl;
    for(ll i=0; i<n; i++) cout << arr[i] << endl;
    cout << endl;
}
