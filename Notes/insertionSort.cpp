#include "iostream"
using namespace std;
void insertionSort(int* arr, int size)
{
    for (int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}
int main()
{
    int arr[5] = {1,5,3,5,10};
    insertionSort(arr, 5);
    for (size_t i = 0; i < 5; i++) cout<< arr[i]<<" ";
    return 0;
}
