#include<iostream>
using namespace std;
#include "iostream"
using namespace std;
class node{
    public:
    node* next, *prev;
    int data;
    node(int data=0):data(data), next(NULL), prev(NULL){}
    friend class DLL;
};
class DLL{
    public:
    node* head, *tail;
    DLL():head(NULL), tail(NULL){}
    void insertHead(int const d){
        node* n = new node(d);
        if(not head) head = n;
        else{
            n->next = head;
            head->prev = n;
            head = n;
        }
    }
    void insertTail(int const d)
    {
        node* n = new node(d);
        if(not tail) head = n;
        else{
            n->prev = tail;
            tail->next = n;
            n = tail;
        }
    }
    void print(){
        node* curr = head;
        while(curr!=NULL){ 
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
	void duplicates()
{
    for (node* i = head; i != NULL; i = i->next)
    {
        node* j = i;
        while (j->next != NULL)
        {
            if (i->data == j->next->data)
            {
                node* temp = j->next;
                j->next = j->next->next;
                if (j->next != NULL)
                    j->next->prev = j;
                else
                    tail = j;
                delete temp;
            }
            else
                j = j->next;
        }
    }
}
};
int main()
{
	DLL l;
	l.insertHead(1);
	l.insertHead(2);
	l.insertHead(3);
	l.insertHead(3);
	l.insertHead(5);
	l.insertHead(1);
	l.print();
	l.duplicates();
	l.print();
	return 0;
}
