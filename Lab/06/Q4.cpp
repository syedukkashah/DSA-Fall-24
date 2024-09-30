#include "iostream"
using namespace std;
class Stack {
    int top, size, *arr;
public:
    Stack() : top(-1){}
    bool isEmpty() {
        return top == -1;
    }
    void push(int x) {
        if (top < size - 1) {
            arr[++top] = x;
        } else {
            cout << "Stack overflow" << endl;
        }
    }
    int peek() const {
        if (top >= 0) return arr[top];
        return 0;
    }
    int pop() {
        if (top >= 0)
        {
             return arr[top--];
        }
        else {
            cout << "Stack underflow" << endl;
            return 0;
        }
    }
    void print()
    {
        for (size_t i = 0; i<= top ; i++)
        {
            cout << arr[i] << " ";
        }
        cout<<endl;
        
    }
};
int main() {
    Stack enqueue, dequeue;
    for (size_t i = 1; i <= 5; i++) enqueue.push(i);
    cout<<"enqueued elements: "<<endl;
    enqueue.print();
    for (size_t i = 1; i <= 3; i++) dequeue.push(enqueue.pop());
    cout<<"dequeued elements: "<<endl;
    dequeue.print();
    cout<<"remaining elements in queue: "<<endl;
    enqueue.print();
    return 0;
}
