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
    void deleteVal(const int val)
    {
        node* curr = head;
        while(curr->next->data!=val) curr = curr->next;
        curr->next = curr->next->next;
        curr->next->next->prev = curr->next;
    }
    void sortList()
    {
        node* curr, *index;
        if(head==NULL) return;
        for(curr = head; curr->next!=NULL; curr = curr->next)
        {
            for (index = curr->next; index!=NULL; index = index->next)
            {
                if(curr->data > index->data)
                {
                    int temp = curr->data;
                    curr->data = index->data;
                    index->data = temp;
                }
            }
        }
        //deleting duplicates
        for(curr = head; curr->next!=NULL; curr = curr->next)
        {
            for (index = curr->next; index!=NULL; index = index->next)
            {
                if(curr->data == index->data)deleteVal(index->data);
            }
        }
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
    list.insertAtEnd(6);
    list.insertAtEnd(3);
    list.insertAtEnd(9);
    list.insertAtEnd(12);
    list.insertAtEnd(12);
    list.insertAtEnd(13);
    list.print();
    list.sortList();
    list.print();
    return 0;
}