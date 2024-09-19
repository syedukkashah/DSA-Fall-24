#include "iostream"
using namespace std;
class node{
    public:
    node* next;
    int data;
    node(int data):next(), data(data){}
    friend class LL;
};
class LL{
    public:
    node* head;
    LL():head(NULL){}
    void insertHead(const int d)
    {
        node* n = new node(d);
        if(!head) head = n;
        else{
            n->next = head;
            head = n;
        }
    }
    void selectionSort()
    {
        if(!head || !(head->next)) return;
        node* curr = head;
        while(curr){
            node *min_node = curr, *temp = curr->next;
            while(temp)
            {
                if(min_node->data > temp->data) min_node = temp;
                temp = temp->next;
            }
            if(min_node!= curr)
            {
                int temp = min_node->data;
                min_node->data = curr->data;
                curr->data = temp;
            }
            curr = curr->next;
        }
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
    l.selectionSort();
    l.print();
    return 0;
}
