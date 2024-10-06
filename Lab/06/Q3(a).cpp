#include "iostream"
#define n 10
using namespace std;
class TicketQueue{
    int *arr, front, rear, passengers = 0;
    public:
    TicketQueue(){
        arr = new int[n];
        front= -1;
        rear = -1;
    }
    void push()
    {
        if(rear == n-1){ 
            cout<<"queue overflow"<<endl;
            return;
        }
        arr[++rear] = ++passengers;
        if(front == -1) front++;
    }
    void pop()
    {
        if(front == -1 || front > rear) 
        {
            cout<<"queue is empty"<<endl;
            return;
        }
        front++;
        passengers--;
    }
    int peek()
    {
        if(front == -1 || front > rear)
        {
            cout<<"queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }
    bool isEmpty()
    {
        return (front == -1 || front > rear);
    }
};

int main() {
    TicketQueue q;
    for (size_t i = 0; i < 10; i++) q.push();
    cout<<q.peek()<<endl;;
    for (size_t i = 0; i < 5; i++) q.pop();
    cout<<q.peek()<<endl;;
    for (size_t i = 0; i < 5; i++) q.push();
    cout<<q.peek()<<endl;
    return 0;
}
