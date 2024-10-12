#include "iostream"
using namespace std;
class Node{
    int data;
    Node* next;
    public:
        Node(int value){
        data = value;
        next = NULL;
    }
    friend class Queue;
};
class Queue{ //we insert from tail in queue, pop from front
    Node *front, *rear; //rear is the tail, front is the head
    public:
    Queue():front(NULL), rear(NULL){}
    bool isEmpty() const{
        return front == NULL;
    }
    void enqueue(const int d)
    {
        if(isEmpty())
        {
            front = rear = new Node(d);
            cout<<"pushed "<<d<<" into the queue"<<endl;
            return;
        }
        else{
            rear->next = new Node(d); 
            rear = rear->next; //we adjust the rear (tail) here
            cout<<"pushed "<<d<<" into the queue"<<endl;
        }
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
            cout<<"dequeued "<<front->data<<"from the queue"<<endl;
            front = rear = NULL;
            return;
        }
        Node* temp = front; 
        cout<<"dequeued "<<front->data<<" from the queue"<<endl;
        front = front->next; //head is adjusted here
        delete temp;
    }
    const int peek()
    {
        if(isEmpty())
        {
            cout<<"queue underflow"<<endl;
            return -1;
        }
        return front->data;
    }
};
int main()
{
    Queue q;
    q.enqueue(5);
    q.enqueue(15);
    q.enqueue(51);
    q.dequeue();
    q.dequeue();
    int x = q.peek();
    if(!q.isEmpty()){
        cout << x << " ";
    }
    return 0;
}
