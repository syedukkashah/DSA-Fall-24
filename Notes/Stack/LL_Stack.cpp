#include "iostream"
using namespace std;
class Node{ 
    Node* next;
    int data;
    public:
    Node(int val = 0):data(val){}
    friend class Stack;
};
class Stack
{
    Node* head;
    public:
    Stack(): head(NULL){}
    bool isEmpty()
    {
        return head == NULL;
    }
    void push(const int d){
        Node* n = new Node(d);
        if(!n){ 
            cout<<"Stack overflow"<<endl;
            return;
        }
        n->next = head;
        head = n;
        cout<<"pushed "<< n->data <<" onto the stack"<<endl;
    }
    void pop()
    {
        if(isEmpty()) cout<<"Stack underflow"<<endl;
        else{
            Node* temp = head;
            cout<<"popped "<<temp->data<<" from the stack"<<endl;
            head = head->next;
            delete temp;
        }
    }
    int peek()
    {
        if(!isEmpty()) return head->data;
        else cout<<"Stack is empty"<<endl;
        return -1;
    }
};
int main()
{
    Stack s;
    s.push(2);
    s.push(4);
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2); 
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
