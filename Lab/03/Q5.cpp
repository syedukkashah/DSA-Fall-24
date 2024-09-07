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
    DLL sort(){
        DLL sortedList;
        node* curr = head;
        while(curr!=NULL)
        {
            curr = curr->next; 
            
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