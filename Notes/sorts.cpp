//bubble sort(outer loop: i=0 -> j< n-1, inner loop = j=0 -> j< n-i-1, if(arr[j]>arr[j+1]) then swap

/*selectionSort(outer loop: i=0 -> i<n, inner loop = j=i+1 -> j<n, min_idx = i before inner loop, 
inside inner loop if(arr[min_idx] > arr[j]) then min_idx = j.
after inner loop swap arr[i] and arr[min_idx] */

/*insertion sort(outer loop goes: i = 1 -> i<n, key = arr[i], j = i-1 before inner loop)
  inner while loop(arr[j]>key && j>=0), inside loop = arr[j+1] = arr[j] (shifting elements to the right), j--, 
  once outside inner loop arr[j+1] = key
*/
#include "iostream"
using namespace std;
class sorting{
    public:
    void bubbleSort(int* arr, int size)
    {
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = 0; j < size-i-1; j++)
            {
                if(arr[j]>arr[j+1])
                {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }
    }
    void selectionSort(int* arr, int size)
    {
        for (size_t i = 0; i < size; i++)
        {
            int min_idx = i;
            for (size_t j = i+1; j < size; j++) 
            {
                if(arr[min_idx] > arr[j]) min_idx = j;
            }
            if(min_idx!=i)
            {
                int temp = arr[min_idx];
                arr[min_idx] = arr[i];
                arr[i] = temp;
            }
        }
    }
    void insertionSort(int* arr, int size)
    {
        for (size_t i = 1; i < size; i++)
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
};

