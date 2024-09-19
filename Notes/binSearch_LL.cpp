#include <iostream>
using namespace std;

class node
{
    private:
        node* next;
        int data;
    public:
        node(int data=0)
        {
            this->data = data;
            next = NULL;
        }

        friend class SLL;
};

class SLL
{
    private:
        node* head;
        int size;
    public:
        SLL(): head(NULL), size(0) {}

        //insert a new node at the front
        void insertAtFront(int value)
        {
            node* newNode = new node(value);

            if(head == NULL)
            {
                head = newNode;
            }
            else
            {
                newNode->next = head;
                head = newNode;
            }
            size++;
        }

        // //method to get middle node between two nodes
        // node* getMiddle(node* start, node* end)
        // {
        //     if(!start)
        //         return nullptr;
            
        //     node* slow = start;
        //     node* fast = start;

        //     while(fast != end && fast->next != end)
        //     {
        //         slow = slow->next;
        //         fast = fast->next->next;
        //     }
        //     return slow;
        // }
        // node* binarySearch(int value)
        // {
        //     node* start = head;
        //     node* end = nullptr;
        //     for(int i = 0; i < size; i++)
        //     {
        //         node* middle = getMiddle(start, end);
        //         if (middle->data == value)
        //         {
        //             return middle;
        //         }
        //         else if (middle->data < value)
        //         {
        //             start = middle->next;
        //         }
        //         else
        //         {
        //             end = middle;
        //         }

        //         if(start == end)
        //         {
        //             break;
        //         }
        //     }
        //     return nullptr;
        // }
        node* getMiddle(node* start, node* end)
        {
            node* slow = start;
            node* fast = start;
            while(fast!=end && fast->next != end)
            {
                slow = slow->next;
                fast = fast->next->next;
            }
            return slow;
        }
        node* binSearch(int val)
        {
            node* start = head;
            node* end = nullptr;
            while(true){
                node* mid = getMiddle(start, end);
                if(!mid) return nullptr;
                if(mid->data == val) return mid;
                else if(start==end) break;
                else if(mid->data < val) start = mid->next;
                else end = mid;
            }
            return nullptr;
        }
        void display()
        {
            node* curr = head;
            while(curr != NULL)
            {
                cout << curr->data << " -> ";
                curr = curr->next;
            }
            cout << "NULL\n";
        }
        node* getHead() { return head; }
};
int main()
{
    SLL list;
    list.insertAtFront(50);
    list.insertAtFront(40);
    list.insertAtFront(30);
    list.insertAtFront(20);
    list.insertAtFront(10);
    node* result;
    //binary search
    node* result = list.binSearch(40);
    if(result)
    {
        cout << "binary search: value " << 40 << " found.\n";
    }
    else
    {
        cout << "binary search: value " << 40 << " not found.\n";   
    }
    return 0;
}
