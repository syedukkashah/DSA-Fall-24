#include "iostream"
using namespace std;
int binSearch(const int arr[], int x, int low, int high)
{
    while(low<=high)
    {
        int mid = low+(high-low) / 2;
        if(arr[mid] == x) return mid;
        else if(arr[mid]<x) low = mid+1;
        else high = mid - 1;
    }
    return -1;
}
int main()
{
    int arr[] = {2, 4, 5, 7, 14, 17, 19, 22};
    int x = 22;
    cout<<binSearch(arr, x, 0, sizeof(arr)/sizeof(arr[0]));
}
