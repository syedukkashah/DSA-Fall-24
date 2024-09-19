#include "iostream"
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int data=0): data(data), next(NULL){}
    friend class LL;
};
class LL{
    public:
    node* head;
    LL(): head(NULL){}
    void insertHead(const int d)
    {
        node* n = new node(d);
        if(!head) head = n;
        else{
            n->next = head;
            head = n;
        }
    }
    void insertionSort()
    {
        if(!head||!(head->next))return;
        node* sorted = nullptr; //new list names sorted
        node* curr = head;
        while(curr)
        {
            node* nextNode = curr->next;
            if(!sorted || sorted->data <= curr->data)
            {
                curr->next = sorted;
                sorted = curr;
            }
            else
            {
                node* temp = sorted;
                while(temp->next && temp->next->data < curr->data)
                {
                    temp = temp->next;
                }
                curr->next = temp->next;
                temp->next = curr;
            }
            curr = nextNode;
        }
        head = sorted;
    }
   
    void print() const
    {
        node* curr = head;
        while(curr){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
int main()
{
    LL l;
    l.insertHead(2);
    l.insertHead(5);
    l.insertHead(1);
    l.insertHead(0);
    l.insertHead(7);
    l.insertHead(4);
    l.insertHead(9);
    l.insertHead(6);
    l.print();
    l.insertionSort();
    l.print();
    return 0;
}
