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
    int passengers = 0;
public:
    TicketQueue() : front(NULL), rear(NULL) {}
    bool isEmpty() const
    {
        return front == NULL;
    }
    void enqueue()
    {
        if (passengers == 10)
        {
            cout << "Queue overflow" << endl;
            return;
        }
        passengers++;
        node *x = new node(passengers);
        if (isEmpty())
        {
            front = x;
            rear = x;
            cout<<"Passenger "<<passengers<<" added to queue"<<endl;
            return;
        }
        else
        {
            x->next = rear;
            rear = x;
            cout<<"Passenger "<<passengers<<" added to queue"<<endl;
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
            front = temp->next;
            if (!front)
                rear = NULL;
            cout<<"Passenger "<<temp->data<<" dequeued"<<endl;
            delete temp;
            passengers--;
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