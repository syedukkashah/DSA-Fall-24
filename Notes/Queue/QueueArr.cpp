#include "iostream"
using namespace std;
class Queue{
    int front,rear,size,*arr;
    public:
    Queue(int n):arr(new int[n]), front(-1), rear(-1), size(n){}
    ~Queue(){delete[] arr;}
    bool isEmpty() const{
        return front == -1 || front > rear;
    }
    bool isFull() const{
        return rear == size -1;
    }
    void push(const int d)
    {
        if(isEmpty())
        {
            front = rear = 0;
            arr[0] = d;
            cout<<"pushed "<< d <<" into the queue"<<endl;
            return;
        }
        if(isFull())
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        rear++;
        arr[rear] = d;
        cout<<"pushed "<< d <<" into the queue"<<endl;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"queue underflow"<<endl;
            return;
        }
        else{
            if(front ==rear)
            {
                cout<<"popped "<<arr[front]<<" out of the queue"<<endl;
                front = rear = -1;
            }
            else{
                front++;
                cout<<"popped "<<arr[front-1]<<" from the queue"<<endl;
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
    q.push(5);
    q.push(15);
    q.push(51);
    q.pop();
    q.pop();
    
    int x = q.peek();
    if(!q.isEmpty()){
        cout << x << " ";
    }
}
