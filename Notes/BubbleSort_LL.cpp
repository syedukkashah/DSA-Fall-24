#include "iostream"
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int data):next(), data(data){}
    friend class SLL;
};
class SLL{
    public:
    node* head;
    SLL():head(NULL){}
    void insertHead(const int d)
    {
        node* n = new node(d);
        if(!head) head = n;
        else{
            n->next = head;
            head = n;
        }
    }
    void bubbleSort()
    {
        bool swapped;
        do{
            swapped = false;
            node* curr = head;
            while(curr && curr->next)
            {
                if(curr->data > curr->next->data)
                {
                    int temp = curr->data;
                    curr->data = curr->next->data;
                    curr->next->data = temp;
                    swapped = true;
                }
                curr = curr->next;
            }
        }while(swapped);
    }
    void print()const{
        node* curr =  head;
        while(curr){ 
            cout<<curr->data<<" ";
            curr = curr->next;
        }
        cout<<endl;
    }
};
int main()
{
    SLL l;
    l.insertHead(2);
    l.insertHead(5);
    l.insertHead(1);
    l.insertHead(0);
    l.insertHead(7);
    l.insertHead(4);
    l.insertHead(9);
    l.insertHead(6);
    l.print();
    l.bubbleSort();
    l.print();
    return 0;
}
