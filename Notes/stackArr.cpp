#include "iostream"
using namespace std;
class Stack{
   int top;
   static const int MAX = 1000;
   int arr[MAX];
   public:
   Stack():top(-1){}
   bool push(const int d)
   {
    if(top>=MAX-1)
    {
        cout<<"Stack Overflow"<<endl;
        return false;
    }
    arr[top++] = d;
    return true;
   }
   bool pop()
   {
    if(top<0)
    {
        cout<<"Stack underflow"<<endl;
        return false;
    }
    return arr[top--];
   }
   int peek()
   {
    if(top<0)
    {
        cout<<"Stack is empty"<<endl;
        return -1;
    }
    return arr[top];
   }
   bool isEmpty(){return top<0;}
};
int main()
{
    Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout<< s.pop()<< " popped from the stack "<< endl;
    cout<< "Top element is: "<< s.peek()<< endl;
    if (s.isEmpty()) {
    cout<< "Stack is empty "<< endl;
    } else {
    cout<< "Stack is not empty "<< endl;}
        return 0;
}
