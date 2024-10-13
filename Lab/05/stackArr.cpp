#include "iostream"
using namespace std;
class Stack{
    int *arr, size, top;
    public:
    Stack(int s)
    {
        size = s;
        top = -1;
        arr = new int [s];
    }
    void push(int val){
        if(top == size-1)
        {
            cout<<"Stack Overflow"<<endl;
            return;
        }
        else {
            top++;
            arr[top] = val;
            cout<<"pushed "<<val<<" into the stack"<<endl;
        }
    }
    void pop()
    {
        if(top == -1)
        {
            cout<<"Stack Underflow"<<endl;
            return;
        }
        else{
            top --;
            cout<<"popped "<< arr[top+1] << " from the stack"<<endl;
        }
    }
    int peek()
    {
        if(top== -1)
        {
            cout<<"Stack is empty"<<endl;
            return -1;
        }
        else return arr[top];
    }
    bool isEmpty(){
        return top == -1;
    }
    int isSize()
    {
        return top+1;
    }
};
int main()
{
    Stack s(5);
    s.push(5);
    s.push(8);
    s.push(7);
    s.pop();
    s.pop();
    s.pop();
    s.pop();
    cout<<s.peek()<<endl;
    s.push(3);
    cout<<s.peek()<<endl;
    cout<<s.isEmpty()<<endl;
    cout<<s.isSize();
    int val = s.peek();
    if(s.isSize()==0) cout<<val;
}
