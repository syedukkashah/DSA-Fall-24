#include "iostream"
using namespace std;
class node{
    int data;
    node* next;
    public:
    node():next(NULL), data(0){}
    node(const int d): data(d), next(NULL){}
    friend class SLL;
};
class SLL{
    node* head;
    public:
    SLL(): head(NULL){}
    SLL(node* n):head(n){}
    void insertAtTail(const int val)
    {
        node* n = new node(val);
        if(head==NULL) head = n;
        else{
            node* curr = head;
            while(curr->next!=NULL)curr = curr->next;
            curr->next = n;
        }
    }
    SLL segregate()
    {
        SLL newList; 
        node* curr = head;
        while(curr!=NULL)
        {
            if(curr->data%2==0)newList.insertAtTail(curr->data); 
            curr = curr->next;
        }
        curr = head; 
        while(curr!=NULL)
        {
            if(curr->data%2!=0)newList.insertAtTail(curr->data); 
            curr = curr->next;
        }
        return newList;
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
    SLL list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);
    list.insertAtTail(6);
    list.print();
    list = list.segregate();
    cout<<"printing segregated list: "<<endl;
    list.print();
    return 0;
}