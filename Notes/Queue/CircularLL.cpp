#include "iostream"
using namespace std;
class node{
    node* next;
    int data;
    public:
    node(int d):data(d), next(NULL){}
    friend class Queue;
};
class Queue{
    node *front, *rear;
    int size, cnt = 0;
    public:
    Queue(int s):front(NULL), rear(NULL), size(s){}
    bool isEmpty() {
        return front == NULL;
    }
    bool isFull()
    {
        return cnt == size;
    }
    void enqueue(int d)
    {
        if(isFull())
        {
            cout<<"queue overflow"<<endl;
            return;
        }
        if(isEmpty())
        {
            front = rear = new node(d);
            rear->next = front;
            cout<<d<<" enqueued"<<endl;
            cnt++;
            return;
        }
        rear->next = new node(d);
        rear->next->next = front;
        rear = rear->next;
        cout<<d<<" enqueued"<<endl;
        cnt++;
    }
    void dequeue()
    {
        if(isEmpty())
        {
            cout<<"queue underflow"<<endl;
            return;
        }
        if(front==rear)
        {
            node* temp = front;
            front = rear = NULL;
            cout<<temp->data<<" dequeued"<<endl;
            delete temp;
            cnt--;
            return;
        }
        node* temp = front;
        front = front->next;
        rear->next = front; //always init rear->next to front when dequeueing
        cout<<temp->data<<" dequeued"<<endl;
        delete temp;
        cnt--;
    }
};
int main()
{
    Queue q(4);
    q.enqueue(1);
    q.enqueue(2);
    q.enqueue(3);
    q.enqueue(4);
    q.enqueue(5);
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    q.dequeue();
    return 0;
}
