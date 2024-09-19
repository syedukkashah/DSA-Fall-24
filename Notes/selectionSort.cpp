#include "iostream"
using namespace std;
void selectionSort(int* arr, int size)
{
    for (size_t i = 0; i < size; i++)
    {
        int min_idx = i;
        for (size_t j = i + 1; j < size; j++)
        {
            if (arr[min_idx] > arr[j]) min_idx = j;
        }
        if(min_idx!=i){
            int temp = arr[i];
            arr[i] = arr[min_idx];
            arr[min_idx] = temp;
        }
    }
}
int main()
{
    int array[5] = {23, 43, 9, 6, 41};
    for (size_t i = 0; i < 5; i++) cout<<array[i]<<" ";
    selectionSort(array, 5);
    for (size_t i = 0; i < 5; i++) cout<<array[i]<<" ";
    return 0;
}
