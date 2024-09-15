#include "iostream"
using namespace std;

class node {
    int data;
    node* next, *prev;
public:
    node() : next(NULL), prev(NULL), data(0) {}
    node(const int d) : data(d), next(NULL), prev(NULL) {}
    friend class DCLL;
};

class DCLL {
    node *head, *tail;
public:
    DCLL() : head(NULL), tail(NULL) {}

    void insertAtEnd(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = tail = n;
            head->next = head;  // Circular link
            head->prev = head;
        } else {
            tail->next = n;
            n->prev = tail;
            n->next = head;  // Circular link to head
            head->prev = n;   // Head's previous points to new tail
            tail = n;
        }
    }

    void insertAtFront(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = tail = n;
            head->next = head;  // Circular link
            head->prev = head;
        } else {
            n->next = head;
            n->prev = tail;
            head->prev = n;
            tail->next = n;  // Circular link to new head
            head = n;        // Update head
        }
    }

    void insertAfterValue(const int after, const int val) {
        node* n = new node(val);
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == after) {
                n->prev = curr;
                n->next = curr->next;
                curr->next->prev = n;
                curr->next = n;
                if (curr == tail) {
                    tail = n;  // Update tail if inserted at the end
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void insertBeforeValue(const int before, const int val) {
        node* n = new node(val);
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == before) {
                n->next = curr;
                n->prev = curr->prev;
                curr->prev->next = n;
                curr->prev = n;
                if (curr == head) {
                    head = n;  // Update head if inserted before the head
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void deleteHead() {
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            node* temp = head;
            tail->next = head->next;
            head->next->prev = tail;
            head = head->next;
            delete temp;
        }
    }

    void deleteTail() {
        if (!tail) {
            cout << "List not found" << endl;
            return;
        }
        if (head == tail) {  // Only one node
            delete head;
            head = tail = NULL;
        } else {
            node* temp = tail;
            tail->prev->next = head;
            head->prev = tail->prev;
            tail = tail->prev;
            delete temp;
        }
    }

    void deleteVal(const int val) {
        if (!head) {
            cout << "List not found" << endl;
            return;
        }
        node* curr = head;
        do {
            if (curr->data == val) {
                if (curr == head) {
                    deleteHead();
                } else if (curr == tail) {
                    deleteTail();
                } else {
                    curr->prev->next = curr->next;
                    curr->next->prev = curr->prev;
                    delete curr;
                }
                return;
            }
            curr = curr->next;
        } while (curr != head);
    }

    void print() {
        if (!head) {
            cout << "List is empty" << endl;
            return;
        }
        node* curr = head;
        do {
            cout << curr->data << " ";
            curr = curr->next;
        } while (curr != head);
        cout << endl;
    }
};

int main() {
    DCLL list;
    
    list.insertAtEnd(1);
    list.insertAtEnd(2);
    list.insertAtEnd(4);
    list.insertAtEnd(5);
    list.print();  // Output: 1 2 4 5
    
    list.insertAtFront(6);
    list.print();  // Output: 6 1 2 4 5
    
    list.insertAfterValue(2, 3);
    list.print();  // Output: 6 1 2 3 4 5
    
    list.insertBeforeValue(3, 9);
    list.print();  // Output: 6 1 2 9 3 4 5
    
    list.deleteVal(9);
    list.print();  // Output: 6 1 2 3 4 5
    
    list.deleteHead();
    list.print();  // Output: 1 2 3 4 5
    
    list.deleteTail();
    list.print();  // Output: 1 2 3 4
    
    return 0;
}
