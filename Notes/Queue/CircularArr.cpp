#include "iostream"
using namespace std;
class Queue{ //The last position is connected back to the first to
             //make a circular queue, solving the limitation of unused 
             //space in a linear queue.
    int front,rear,size,*arr;
    public:
    Queue(int n):arr(new int[n]), front(-1), rear(-1), size(n){}
    ~Queue(){delete[] arr;}
    bool isEmpty() const{
        return front == -1;
    }
    bool isFull() const{
        return (rear +1) % size == front; //if front idx = 0, rear = 4 (assuming size = 5), (4+1)%5=0 
    }
    void enqueue(const int d)
    {
        if(isEmpty())
        {
            front = rear = 0;
            arr[0] = d;
            cout<<"enqueued "<< d <<" into the queue"<<endl;
            return;
        }
        if(isFull())
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        rear = (rear+1)%size; //rear moves in a circular manner
        arr[rear] = d;
        cout<<"enqueued "<< d <<" into the queue"<<endl;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue underflow"<<endl;
            return;
        }
        else{
            if(front ==rear)
            {
                cout<<"dequeued "<<arr[front]<<" out of the queue"<<endl;
                front = rear = -1;
            }
            else{
                front = (front+1)%size;
                cout<<"dequeued "<<arr[front-1]<<" from the queue"<<endl;
            }
            

        }
            }
    const int peek()
    {
        if(isEmpty())
        {
            cout<<"queue underflow"<<endl;
            return -1;
        }
        return arr[front];
    }
};
int main()
{
    Queue q(5);
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(51);
    q.dequeue();
    q.dequeue();
    int x = q.peek();
    if(!q.isEmpty()){
        cout << x << " ";
    }
}
