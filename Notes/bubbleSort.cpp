#include "iostream"
using namespace std;
void swap(int* a, int* b)
{
    int* temp = a;
    a = b;
    b = temp;
    delete temp;
}
void bubbleSort(int* arr, int size) //O(n²)
{
    bool swapFlag = false;
    for (size_t i = 0; i < size - 1; i++){
        swapFlag = false; //reset flag for each iteration
        for (size_t j = 0; j < size - i - 1; j++){
            if(arr[j]>arr[j+1])
            { 
                swap(arr[j], arr[j+1]);
                swapFlag = true;
            }
        }
        if (!swapFlag) break; //if no swaps were made, the array is sorted
    }
}
int main()
{
    int arr[5] = {1,4,7,3,9};
    for (size_t i = 0; i < 5; i++) cout<<arr[i]<<" ";
    return 0;
    bubbleSort(arr, 5);
    for (size_t i = 0; i < 5; i++) cout<<arr[i]<<" ";
    return 0;
}
