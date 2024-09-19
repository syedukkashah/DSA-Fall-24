#include "iostream"
using namespace std;
class node{
    int data;
    node* next;
    public:
    node(int val):data(val), next(NULL){}
    friend class Stack;
};
class Stack{
    node* top;
    public:
    Stack(): top(NULL){}
    void push(int value)
    {
        node* n = new node(value);
        n->next = top;
        top = n;
        cout<<value<<" pushed on to the stack"<<endl;
    }
    int pop()
    {
        if(!top)
        {
            cout<<"Stack underflow. Cannot pop"<<endl;
            return -1;
        }
        node* temp = top;
        int popped = top->data;
        top = top->next;
        delete temp;
        return popped;
    }
    int peek()
    {
        if(!top)
        {
            cout<<"Stack is empty. Nothing to peek"<<endl;
            return -1;
        }
        return top->data;
    }
    bool isEmpty(){return top == NULL;}
    ~Stack(){
        while(top)
        {
            node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<<s.pop()<<" popped from the Stack"<<endl;
    cout<<"top element is "<<s.peek()<<endl;
    if(s.isEmpty())
    {
        cout<<"Stack is empty"<<endl;
    }
    else{
        cout<<"Stack is not empty"<<endl;
    }
    return 0;
}
