#include "iostream"
using namespace std;
class stack{
    public:
    int top;
    int size;
    int *arr;
    stack(int size):top(-1), size(size){arr = new int[size];}
    bool is_empty(){
        return top == -1;
    }
    void push(int x)
    {
        if(top<size-1)
        {
            arr[++top] = x;
        }
        else return;
    }
    int peek() const{
        if(top<size-1) return arr[top];
        return 0;
    }
    int pop()
    {
        if(top>=0) return arr[top--];
        return 0;
    }
    void print(){
        for(int i = 0; i <= top; i++)cout << arr[i] << " ";
    }
};
int main()
{
   stack s(8);
   s.push(1);
   s.push(2);
   s.push(3);
   s.push(4);
   s.push(5);
   s.push(6);
   s.push(7);
   s.push(8);
   stack even(8), odd(8);
   for (int i=0; i<8; i++)
   {
    int val = s.pop();
    if(val%2 == 0) even.push(val);
    else odd.push(val);
   }
   cout<<"even stack: ";
   even.print();
   cout<<"\nodd stack: ";
   odd.print();
   return 0;
}
