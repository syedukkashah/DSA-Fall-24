#include "iostream"
using namespace std;
int non_tail_factorial(int n) {
    if (n == 0) {
        return 1;
    } else {
        return n * non_tail_factorial(n - 1);
    }
}
int tail_factorial(int n, int acc = 1) {
    if (n == 0) {
        return acc;
    } else {
        return tail_factorial(n - 1, acc * n);
    }
}
int main()
{
    cout<<tail_factorial(5)<<endl;
    cout<<non_tail_factorial(5)<<endl;
    return 0;
}
