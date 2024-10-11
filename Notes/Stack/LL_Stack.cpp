#include "iostream"
using namespace std;
class Node{
    Node* next;
    int data;
    public:
    Node(const int d):data(d), next(nullptr){}
    friend class Stack;
};
class Stack{
    Node* head;
    public:
    Stack():head(nullptr){}
    bool isEmpty() const{
        return head == nullptr;
    }
    void push(const int val)
    {
        Node* newNode = new Node(val);
        if (isEmpty())
        {
            head = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
        cout<<"pushed "<<newNode->data<<" onto the stack"<<endl;
    }
    void pop()
    {
        if(isEmpty())
        {
            cout<<"stack underflow "<<endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        cout<<"popped "<<temp->data<<" from the stack"<<endl;
        delete temp;
    }
    int peek() const{
        if(isEmpty()) return -1;
        return head->data;
    }
};
int main()
{
    Stack s;
    s.pop();
    s.push(2);
    s.push(4);
    s.push(6);
    s.push(8);
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
}
