#include <iostream>
using namespace std;

class node {
    int data;
    node* next;
public:
    node() : data(0), next(NULL) {}
    node(int d) : data(d), next(NULL) {}
    friend class SLL;
};

class SLL {
    node* head;
public:
    SLL() : head(NULL) {}
    void insertAtTail(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
        } else {
            node* current = head;
            while (current->next != NULL) {
                current = current->next;
            }
            current->next = n;
        }
    }

    void reverse() {
        node* prev = NULL;
        node* curr = head;
        node* next = NULL;
        while (curr != NULL) {
            next = curr->next;  
            curr->next = prev;  
            prev = curr;        
            curr = next;        
        }
        head = prev; 
    }
    void printList() {
        node* currentPtr = head;
        while (currentPtr != NULL) {
            cout << currentPtr->data << " ";
            currentPtr = currentPtr->next;
        }
        cout << endl;
    }
};

int main() {
    SLL list;
    list.insertAtTail(1);
    list.insertAtTail(2);
    list.insertAtTail(3);
    list.insertAtTail(4);
    list.insertAtTail(5);

    cout << "Original list: ";
    list.printList();
    list.reverse();
    cout << "Reversed list: ";
    list.printList();

    return 0;
}
