/*after removing the first 5 passengers, more passengers can't be added even though there are
available spaces at the front of the array. Since queue is linear, rear ptr doesn't wrap around to 
reuse the freed spaces at the front. To solve this, we need to implement a circular queue. 
In a circular queue, the rear pointer wraps around to the beginning of the array when it reaches the end, 
allowing us to reuse the freed space at the front.*/

#include "iostream"
#define n 10
using namespace std;
class TicketQueue {
    int *arr, front, rear, passengers = 0, size = 0;
public:
    TicketQueue() {
        arr = new int[n];
        front = -1;
        rear = -1;
    }
    void push() {
        if (size == n) {  
            cout << "queue overflow" << endl;
            return;
        }
        rear = (rear + 1) % n;
        arr[rear] = ++passengers;
        size++;
        if (front == -1) {  
            front = rear;
        }
    }
    void pop() {
        if (size == 0) {  
            cout << "queue is empty" << endl;
            return;
        }
        front = (front + 1) % n;
        size--;
        passengers--;
    }
    int peek() {
        if (size == 0) {  
            cout << "queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    bool isEmpty() {
        return size == 0;
    }
};

int main() {
    TicketQueue q;
    for (size_t i = 0; i < 10; i++) q.push();
    cout << q.peek() << endl;
    for (size_t i = 0; i < 5; i++) q.pop();
    cout << q.peek() << endl;
    // Add 5 more passengers (wrap around)
    for (size_t i = 0; i < 5; i++) q.push();
    cout << q.peek() << endl;
    return 0;
}
