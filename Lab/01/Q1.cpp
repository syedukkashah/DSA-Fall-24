#include "iostream"
using namespace std;
class BankAccount
{
public:
    double balance;
    BankAccount(double balance = 500) { this->balance = balance; }
    BankAccount(BankAccount &obj) { this->balance = obj.balance; }
};
int main()
{
    BankAccount account1, account2(1000), account3;
    cout << account1.balance << endl;
    cout << account2.balance << endl;
    account3 = account2;
    account3.balance -= 200;
    cout << account3.balance << endl;
    return 0;
}
