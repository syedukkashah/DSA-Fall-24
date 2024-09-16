#include "iostream"
using namespace std;
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int getMax(int arr[], int n) {
    int max = 0;
    for (int i=1; i<n; i++) {
        if (arr[i] > arr[max])
            max = i;
    }
    return max;
}
void recursiveSort(int arr[], int n) {
    if (n == 1)
        return;
    int max = getMax(arr, n);
    swap(&arr[n-1], &arr[max]);
    recursiveSort(arr, n-1);
}

int main()
{
    int arr[5] = {5,3,4,2,1};
    for (size_t i = 0; i < 5; i++) cout<<arr[i]<<" ";
    recursiveSort(arr, 5);
    for (size_t i = 0; i < 5; i++) cout<<arr[i]<<" ";
}
