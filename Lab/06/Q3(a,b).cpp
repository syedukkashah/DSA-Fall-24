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
    q.peek();
    return 0;
}
/*Q3(b) after removing the first 5 passengers, more passengers can't be added even though there are
available spaces at the front of the array. Since queue is linear, rear ptr doesn't wrap around to 
reuse the freed spaces at the front*/
