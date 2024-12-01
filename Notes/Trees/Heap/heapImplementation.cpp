#include "iostream"
#include "vector"
#include "queue"
using namespace std;
class MaxHeap{
    void HeapifyUP(int index)
    {
        while(index>0 && heap[index]>heap[(index-1)/2])
        {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void HeapifyDOWN(int index)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 2;
        if(left < heap.size() && heap[largest]<heap[left]) largest = left;
        if(right < heap.size() && heap[largest]<heap[right]) largest = right;
        if(largest!=index)
        {
            swap(heap[index], heap[largest]);
            HeapifyDOWN(largest);
        }
    }
    public:
    
    vector<int> heap;
    void enqueue(int d)
    {   
        heap.push_back(d);
        HeapifyUP(heap.size()-1);
    }
    void dequeue()
    {
        heap.pop_back();
        HeapifyDOWN(0);
    }
    void print()
    {
        for(int i: heap) cout<<i<<" ";
    }
};
class MinHeap{
    void HeapifyUP(int index)
    {
        while(index>0 && heap[index]<heap[(index-1)/2])
        {
            swap(heap[index], heap[(index-1)/2]);
            index = (index-1)/2;
        }
    }
    void HeapifyDOWN(int index)
    {
        int largest = index;
        int left = 2*index + 1;
        int right = 2*index + 1;
        if(left < heap.size() && heap[largest]>heap[left]) largest = left;
        if(right < heap.size() && heap[largest]>heap[right]) largest = right;
        if(largest!=index)
        {
            swap(heap[index], heap[largest]);
            HeapifyDOWN(largest);
        }
    }
    public:
    
    vector<int> heap;
    void enqueue(int d)
    {   
        heap.push_back(d);
        HeapifyUP(heap.size()-1);
    }
    void dequeue()
    {
        heap.pop_back();
        HeapifyDOWN(0);
    }
    void print()
    {
        for(int i: heap) cout<<i<<" ";
    }
};
int main()
{
    MaxHeap maxHeap;
    MinHeap minHeap;
    maxHeap.enqueue(10);
    maxHeap.enqueue(20);
    maxHeap.enqueue(15);
    maxHeap.enqueue(27);
    maxHeap.enqueue(18);
    maxHeap.enqueue(23);
    maxHeap.enqueue(9);
    maxHeap.enqueue(4);
    maxHeap.enqueue(98);
    maxHeap.enqueue(45);
    maxHeap.print();
    cout<<endl;
    minHeap.enqueue(10);
    minHeap.enqueue(20);
    minHeap.enqueue(15);
    minHeap.enqueue(27);
    minHeap.enqueue(18);
    minHeap.enqueue(23);
    minHeap.enqueue(9);
    minHeap.enqueue(4);
    minHeap.enqueue(98);
    minHeap.enqueue(45);
    minHeap.print();
    return 0;
}
