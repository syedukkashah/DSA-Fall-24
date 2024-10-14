#include "iostream"
using namespace std;
int findPivot(int* arr, int low, int high){
    int i = low, j = high;
    int pivot = arr[low];
    while(i<j)
    {
        while(arr[i]<=pivot && i<=high-1) i++;
        while(arr[j]>pivot && j>=low+1) j--;
        if(i<j)
        {
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;
    return j;
}
void quickSort(int* arr, int low, int high)
{
    if(low<high)
    {
        int pivotPos = findPivot(arr, low, high);
        quickSort(arr, low, pivotPos-1);
        quickSort(arr, pivotPos+1, high);
    }
}

void merge(int* arr, int low, int mid, int high)
{
    int i = low,j = mid+1, k = 0;
    int* temp = new int[high-low+1];
    while(i<=mid && j<=high)
    {
        if(arr[i]<=arr[j])
        {
            temp[k] = arr[i];
            i++;
        }
        else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    while(i<=mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while(j<=high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (size_t idx = 0; idx<k; idx++)
    {
        arr[low+idx] = temp[idx];
    }
    delete[] temp;
}
void mergeSort(int* arr,int low,int high)
{
    if(low>=high)return;
    int mid = low + (high - low)/2;
    mergeSort(arr, low, mid);
    mergeSort(arr, mid+1, high);
    merge(arr, low, mid, high);
}
