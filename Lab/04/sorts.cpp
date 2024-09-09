#include <iostream>
using namespace std;
#define size 5

//int* array = {21, 43, 24, 98, 123};

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


void printArray(int* arr)
{
    for(int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n";
}

int main()
{
    int array1[] = {21, 43, 28, 45, 78};

    cout << "before bubble sort:\n";
    printArray(array1);

    bubbleSort(array1);

    cout << "after bubble sort:\n";
    printArray(array1);

    int array2[] = {22, 43, 88, 45, 78};

    cout << "\nbefore selection sort:\n";
    printArray(array2);

    selectionSort(array2);

    cout << "after selection sort:\n";
    printArray(array2);

    int array3[] = {25, 73, 88, 95, 78};

    cout << "\nbefore insertion sort:\n";
    printArray(array3);

    insertionSort(array3);

    cout << "after insertion sort:\n";
    printArray(array3);

    return 0;
}