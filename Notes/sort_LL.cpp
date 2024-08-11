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
    int arr[4] = {235, 6, 89, 95}; //random set of nums
    for (size_t i = 0; i < 4; i++)
    {
        node* n = new node();
        if(n==NULL) return 1;
        n->data = arr[i]; 
        n->next = NULL;
        //if list is empty
        if (list == NULL) list = n; //this node is the whole list
        else if(n->data < list->data){ //if num belongs at beggining of list
            n->next = list;
            list = n;
        }
        //if num belongs later in the list
        else{
            
            for (node* ptr = list; ptr!=NULL; ptr = ptr->next)
            {
                //if at end
                if(ptr->next == NULL)
                {
                    //append mode
                    ptr->next = n; //we add the new node to the end of the list, hence appending
                    break;
                }
                //if in middle of list
                if(n->data < ptr->next->data)
                {
                    n->next = ptr->next;
                    ptr->next = n;
                    break;
                }
            }
        }
    }
    for(node* ptr = list; ptr!=NULL; ptr = ptr->next)
    cout<<ptr->data<<endl;
    return 0;
}
