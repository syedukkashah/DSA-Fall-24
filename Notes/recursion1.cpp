#include "iostream"
using namespace std;
class Recursion{
    public:
    int static factorial(int n)
   {
    if(n==1 || n==0) return 1; //factorial of 0 is also 1
    else return n* factorial(n-1);
   }
   int static sumOfNaturalNums(int n)
   {
    if(n==1) return 1;
    else return n + sumOfNaturalNums(n-1);
   }
   int static fibonacci(int n) //n will be incremented in main
   {
    if(n==0 || n== 1) return n;
    else return fibonacci(n-1) + fibonacci(n-2); //return sum of last two terms
   }
   void static fibonacci2(int a, int b, int n) //for this variant 0 & 1 need to be printed in main
   {
    if(n==0) return;
    int c = a+b;
    cout<<c<<" "; //printing is done in function
    fibonacci2(b,c,n-1);
   }
   int static power(int x, int n) //stack height = n
   {
    if(n==0) return 1;
    if(x==0) return 0;
    else return x * power(x, n-1);
   }
};
int main()
{
    cout<<Recursion::factorial(5)<<endl;
    cout<<Recursion::sumOfNaturalNums(5)<<endl;
    for (size_t i = 0; i < 5; i++)cout<<Recursion::fibonacci(i)<<" ";
    cout<<endl;
    Recursion::fibonacci2(0,1,5);
    cout<<endl;
    cout<<Recursion::power(2,3)<<endl;
}
