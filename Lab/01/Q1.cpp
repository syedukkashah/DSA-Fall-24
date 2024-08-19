#include "iostream"
using namespace std;
class BankAccount
{
public:
    double* ptr;
    public:
    BankAccount(double balance = 500) { ptr= new double (balance); }
    BankAccount(BankAccount &obj) { ptr = new double (*obj.ptr); }
    void setBalance(const double balance)
    {
        ptr = NULL;
        ptr = new double(balance);
        return;
    }
    double getBalance() const{return *ptr;}
    ~BankAccount(){delete ptr;}
};
int main()
{
    BankAccount account1, account2(1000), account3;
    cout << account1.getBalance() << endl;
    cout << account2.getBalance() << endl;
    account3 = account2;
    account3.setBalance(account3.getBalance()-200);
    cout << account3.getBalance() << endl;
    return 0;
}
