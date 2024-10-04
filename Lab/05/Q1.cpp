#include "iostream"
using namespace std;
#define SIZE 5
int* REVERSE(int* arr)
{
    for (size_t i = 0; i <= SIZE/2; i++)
    {
        int temp = arr[SIZE-i-1];
        arr[SIZE-i-1] = arr[i];
        arr[i] = temp;
    }
    return arr;  
}
int* reverse(int size, int* arr, int i)
{
    if(i == size / 2)return arr;
    int temp = arr[size - i - 1];
    arr[size-i-1] = arr[i];
    arr[i] = temp;
    return reverse(size, arr, i+1);
}
int main()
{
    int arr[SIZE] = {1, 2, 3, 4, 5};
    reverse(5,arr,0);
    for (size_t i = 0; i < 5; i++) cout<<arr[i]<<endl;
}
