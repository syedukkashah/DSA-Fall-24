#include <iostream>
using namespace std;
#define size 5
void bubbleSort(int* arr)
{
    for(int i = 0; i < size; i++)
    {
        for(int j = 0; j < size - i - 1; j++)
        {
            if(arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
void shellSort(int* arr)
{
    for (int gap = size/2; gap > 0; gap /= 2){
        for (int i = gap; i < size; i += 1)
        {
            int temp = arr[i];
            int j;            
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) arr[j] = arr[j - gap];
            arr[j] = temp;
        }
    }
}
void selectionSort(int* arr)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min_idx = i;
        for(int j = i + 1; j < size; j++)
        {
            if(arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }
        if(min_idx != i)
        {
            int temp = arr[min_idx];
            arr[min_idx] = arr[i];
            arr[i] = temp;
        }
    }
}

void insertionSort(int* arr)
{
    for(int i = 1; i < size; i++)
    {
        int key = arr[i];
        int j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
void combSort(int *arr) {
   int gap = size;
   bool flag = true;
   while(gap != 1 || flag == true) {
      gap = (gap*10)/13; 
      if(gap<1)
         gap = 1;
      flag = false;
     for(int i = 0; i<size-gap; i++) { 
         if(arr[i] > arr[i+gap]) {
            int temp = arr[i+gap];
            arr[i+gap] = arr[i];
            arr[i] = temp;
            flag = true;
         }
      }
   }
}
void print(int* arr)
{
    for(int i = 0; i < size; i++) cout << arr[i] << " ";
    cout << "\n";
}
int linear_search(int* arr, int search)
{
    for (int i = 0; i < size; i++)
        if (arr[i] == search)
            return i;
    return -1;
}
 
int main()
{
    int array1[] = {21, 43, 28, 45, 78};
    cout << "before bubble sort:\n";
    print(array1);
    bubbleSort(array1);
    cout << "after bubble sort:\n";
    print(array1);
    int array2[] = {22, 43, 88, 45, 78};
    cout << "\nbefore selection sort:\n";
    print(array2);
    selectionSort(array2);
    cout << "after selection sort:\n";
    print(array2);
    int array3[] = {25, 73, 88, 95, 78};
    cout << "\nbefore insertion sort:\n";
    print(array3);
    insertionSort(array3);
    cout << "after insertion sort:\n";
    print(array3);
    int array4[] = {25, 73, 88, 95, 78};
    cout << "\nbefore shell sort:\n";
    print(array4);
    shellSort(array4);
    cout << "after shell sort:\n";
    print(array4);
    int array5[] = {25, 73, 88, 95, 78};
    cout << "\nbefore comb sort:\n";
    print(array5);
    combSort(array5);
    cout << "after comb sort:\n";
    print(array5);
    int result = linear_search(array5,95);
    (result == -1) ? 
    cout << "Element is not present in array" : 
    cout << "Element is present at index " << result;
    return 0;
}