/*after removing the first 5 passengers, more passengers can't be added even though there are
available spaces at the front of the array. Since queue is linear, rear ptr doesn't wrap around to 
reuse the freed spaces at the front. To solve this, we need to implement a circular queue. 
In a circular queue, the rear pointer wraps around to the beginning of the array when it reaches the end, 
allowing us to reuse the freed space at the front.*/

#include <iostream>
using namespace std;

class Ticket{
    int *arr;
    int passenger;
    int size;
    int front;
    int rear;

public:
    Ticket(){
        size = 10;
        arr = new int[size];
        passenger = 0;
        front = -1;
        rear = -1;
    }

    ~Ticket(){
        delete[] arr;
    }

    bool isEmpty(){
        return front == -1;
    }

    bool isFull(){
        return (rear + 1) % size == front;
    }

    void push(){
        if (isEmpty()){
            front = rear = 0;
            passenger++;
            arr[rear] = passenger;
        }
        else if (isFull()){
            cout << "Queue overflow" << endl;
        }
        else{
            rear = (rear + 1) % size;
            passenger++;
            arr[rear] = passenger;
        }
    }

    void pop(){
        if (isEmpty()){
            cout << "Queue underflow" << endl;
        }
        else{
            if (front == rear){
                front = rear = -1; 
            }
            else{
                front = (front + 1) % size;
            }
        }
    }

    int peek(){
        if (isEmpty()){
            cout << "Queue Underflow" << endl;
            return -1;
        }
        else{
            return arr[front];
        }
    }

    void print(){
        if (!isEmpty()){
            cout << "Queue: ";
            int i = front;
            while(true){
                cout << arr[i] << " ";
                if (i == rear) 
                    break; 
                i = (i + 1) % size;  
            }
            cout << endl;
        }
        else{
            cout << "Queue is empty." << endl;
        }
    }
};
