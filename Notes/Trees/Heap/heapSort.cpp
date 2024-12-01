#include "iostream"
#include "vector"
using namespace std;
void heapify(vector<int>& arr,int index)
{
    int largest = index;
    int left = 2*index + 1, right = 2*index +2;
    if(left<arr.size() && arr[left]>arr[largest]) largest = left;
    if(right<arr.size() && arr[right]>arr[largest]) largest = right;
    if(largest!=index)
    {
        swap(arr[largest], arr[index]);
        heapify(arr, largest);
    }
}
void heapSort(vector<int>& arr)
{
    //build max heap first 
    for(int i = arr.size()/2 - 1; i>=0; i--) heapify(arr,i);

    for(int i=arr.size()-1; i>=0; i--)
    {
        swap(arr[0], arr[i]);
        heapify(arr,i);
    }
}
void print(vector<int> arr)
{
    for(int i: arr)cout<<i<<" ";
    cout<<endl;
}
int main()
{
    vector <int> arr = {12, 11, 13, 5, 6, 7};
    print(arr);
    heapSort(arr);
    print(arr);
    return 0;
}