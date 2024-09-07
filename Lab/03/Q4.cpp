#include "iostream"
using namespace std;
class node{
    int data;
    node* next, *prev;
    public:
    node():next(NULL), prev(NULL), data(0){}
    node(const int d): data(d), next(NULL), prev(NULL){}
    friend class DLL;
};
class DLL{
    node *head, *tail;
    public:
    DLL():head(NULL), tail(NULL){}
    void insertAtEnd(const int val)
    {
        node* n = new node(val);
        if(head==NULL)head = tail = n;
        else{
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
    }
    void insertAtFront(const int val)
    {
        node* n = new node(val);
        if(head==NULL)head = tail = n;
        else{
            head->prev = n;
            n->next = head;
            head = n;
        }
    }
    void insertAfterValue(const int after, const int val)
    {
        node* n = new node(val);
        if(not head){ 
            cout<<"list not found"<<endl;
            return;
        }
        node* curr = head;
        while(curr->data!=after) curr=curr->next;
        n->prev = curr;
        n->next =  curr->next;
        curr->next = n;
    }
    void insertBeforeValue(const int before, const int val)
    {
        node* n = new node(val);
        if(not head)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* curr = head;
        while(curr->next->data!=before) curr = curr->next;
        n->prev = curr;
        n->next = curr->next;
        curr->next = n;
    }
    void deleteHead()
    {
        if(not head)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* temp = head;
        head = head->next;
        if(head) head->prev = NULL;
        else tail = NULL;
        delete temp;
    }
    void deleteTail()
    {
        if(not tail)
        {
            cout<<"list not found"<<endl;
            return;
        }
        node* temp = tail;
        tail = tail->prev;
        if(tail)tail->next = NULL;
        else head = NULL;
        delete temp;
    }
    void deleteVal(const int val)
    {
        node* curr = head;
        while(curr->next->data!=val) curr = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr->next;
    }
    void print()
    {
        node* curr = head;
        while(curr!=NULL){
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
int main()
{
    DLL list;
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.print();
    list.insertAtFront(6);
    list.print();
    list.insertAfterValue(2,3);
    list.print();
    list.insertBeforeValue(3, 9);
    list.print();
    list.deleteVal(9);
    list.print();
    list.deleteHead();
    list.print();
    list.deleteTail();
    list.print();
    return 0;
}