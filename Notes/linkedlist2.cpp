#include "iostream"
using namespace std;
class node{
    public:
    int data;
    node* next;
};
int main()
{
    node* list = NULL;
    for (size_t i = 0; i < 4; i++)
    {
        node* n = new node();
        n->data = i;
        n->next = list; // points to the node already in the list
        list = n; //the list now points to the new node
    }
    node* ptr = list; //we use ptr to iterate through the list
    while (ptr!=nullptr)
    {
        cout<<ptr->data<<endl; //prints the data in first node
        ptr = ptr->next; //repositions pointer to point at the next node
    }
    return 0;
}
