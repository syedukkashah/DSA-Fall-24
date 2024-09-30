#include "iostream"
#define size 10
using namespace std;
class node
{
    node *next;
    int data;
public:
    node(const int d = 0) : data(d), next(NULL) {}
    friend class TicketQueue;
};

class TicketQueue
{
    node *front, *rear;
    int currentPassengerNumber = 0;  
    int queueSize = 0;               
public:
    TicketQueue() : front(NULL), rear(NULL) {}
    bool isEmpty() const
    {
        return front == NULL;
    }
    void enqueue()
    {
        if (queueSize == size)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        currentPassengerNumber++;
        node *x = new node(currentPassengerNumber);
        if (isEmpty())
        {
            front = x;
            rear = x;
            cout<<"Passenger "<<currentPassengerNumber<<" added to queue"<<endl;
            return;
        }
        else
        {
            rear->next = x;
            rear = x;
            cout<<"Passenger "<<currentPassengerNumber<<" added to queue"<<endl;
            queueSize++;
        }
    }
    void dequeue()
    {
        if (isEmpty())
        {
            cout << "Queue underflow" << endl;
            return;
        }
        else
        {
            node *temp = front;
            front = front->next;
            if (!front)
                rear = NULL;
            cout<<"Passenger "<<temp->data<<" dequeued"<<endl;
            delete temp;
            queueSize--;
        }
    }
    int peek()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return front->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return;
        }
        node *curr = front;
        cout << "Passengers in Queue: " << endl;
        while (curr)
        {
            cout << curr->data << endl;
            curr = curr->next;
        }
    }
};
int main()
{
    TicketQueue q;
    for (size_t i = 0; i < 10; i++)
        q.enqueue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    for (size_t i = 0; i < 5; i++)
        q.dequeue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    for (size_t i = 0; i < 5; i++)
        q.enqueue();
    cout <<"Passenger at front of queue: "<< q.peek() << endl;
    return 0;
}
