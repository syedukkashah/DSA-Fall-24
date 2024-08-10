//1st attempt at making a linked list
#include "iostream"
using namespace std;
class IntSLLNode{
    public:
    IntSLLNode* next;
    int info;
    IntSLLNode(){next=NULL;}
    IntSLLNode(int i, IntSLLNode* in = NULL){info = i; next = in;}
};
int main()
{
    IntSLLNode* p = new IntSLLNode(10, new IntSLLNode(8, new IntSLLNode(11)));
    IntSLLNode* ptr = p;
    for (size_t i = 0; ptr!=NULL; i++)
    {
        cout << ptr->info << endl;
        ptr = ptr->next;
    }
}
