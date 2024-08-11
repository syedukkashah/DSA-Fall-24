#include "iostream"
using namespace std;
class node{
    public:
    int data;
    node* next;
};
int main()
{
    //memory for nums
    node* list = NULL;
    for (size_t i = 0; i < 4; i++)
    {
        node* n = new node();
        if(n==NULL) return 1;
        n->data = i;
        n->next = NULL;
        //if list is empty
        if (list == NULL) list = n; //this node is the whole list
        //if list has nums already
        else{
            for (node* ptr = list; ptr!=NULL; ptr = ptr->next)
            {
                if(ptr->next == NULL)//if the next node is NULL, end of list has been reached
                {
                    //append mode
                    ptr->next = n; //we add the new node to the end of the list, hence appending
                    break;
                }
            }
        }
    }
    for(node* ptr = list; ptr!=NULL; ptr = ptr->next)
    cout<<ptr->data<<endl;
    return 0;
}
