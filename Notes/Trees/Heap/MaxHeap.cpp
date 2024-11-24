#include "iostream"
#include "queue"
using namespace std;
class Node{
    Node *left, *right;
    int data;
    public:
    Node(int d):data(d), right(NULL), left(NULL){}
};
class MaxHeap{
    int* arr, size, total_size; //total element in heap & total size of arr
    public:
    MaxHeap(int n)
    {
        arr = new int[n];
        size = 0;
        total_size = n;
    }
    void insert(int d)
    {
        if(size==total_size)
        {
            cout<<"Heap Overflow"<<endl;
            return;
        } 
        arr[size] = d;
        int index = size;
        size++;

        //compare it with it's parent
        while(index>=0 && arr[index]>arr[(index-1)/2])
        {
            swap(arr[index], arr[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void print(){
        for(int i=0; i<size; i++)cout<<arr[i]<<" ";
        cout<<endl;
    }

    void Heapify(int index)
    {
        int largest = index;
        int left = 2*index +1;
        int right = 2*index +2;

        //store largest element b/w left, right & parent
        if(left<size&&arr[left]>arr[largest]) largest = left;
        if(right<size&&arr[right]>arr[largest]) largest = right;
        if(largest!=index)
        {
            swap(arr[index], arr[largest]);
            Heapify(largest);
        } 
    }

    void Delete()
    {
        if(size==0)
        {
            cout<<"Heap Underflow"<<endl;
            return;
        }
        cout<<arr[0]<<" deleted from the heap"<<endl;
        arr[0] = arr[size-1];
        size--;
        if(size==0)return;

        Heapify(0);
    }
};
void Heapify(int arr[], int index, int n)
{
    int largest = index;
    int left = 2*index + 1;
    int right = 2*index + 2; 
    if(left<n && arr[largest]<arr[left]) largest = left; //for minHeap we will check if largest val > 
    if(right<n && arr[largest]<arr[right]) largest = right;
    if(largest!=index)
    {
        swap(arr[largest], arr[index]);
        Heapify(arr, largest, n);
    }
}
void printHeap(int arr[], int n)
{
    for(int i=0; i<n; i++) cout<<arr[i]<<" ";
    cout<<endl;
}
void BuildMaxHeap(int arr[], int n)
{
    for(int i=n/2 -1; i>=0; i--) Heapify(arr, i, n);
}
int main()
{
    MaxHeap h(7);
    h.insert(4);
    h.insert(14);
    h.insert(11);
    h.Delete();
    h.print();
    h.insert(114);
    h.insert(24);
    h.insert(1);
    h.insert(10);
    h.print();
    h.print();
    h.Delete();
    h.Delete();
    h.Delete();
    h.print();
    h.Delete();
    h.print();

    int arr[] = {10,3,8,9,5,13,18,14,11,70};
    BuildMaxHeap(arr,10);
    printHeap(arr,10);
    return 0;
}
