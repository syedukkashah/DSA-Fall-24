#include "iostream"
using namespace std;
class node {
    int data;
    node* next;
public:
    node() : data(0), next(NULL) {}
    node(const int d) : data(d), next(NULL) {}
    friend class CSLL;
};
class CSLL {
    node* head;
public:
    CSLL() : head(NULL) {}
    void insertAtFront(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            head->next = head;  // Circular link to itself
        } else {
            node* curr = head;
            // Traverse to the last node to update the circular link
            while (curr->next != head) {
                curr = curr->next;
            }
            n->next = head;  // Insert the new node before the head
            curr->next = n;   // Last node points to new head
            head = n;         // Update head
        }
    }
    void insertAtTail(const int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            head->next = head;  // Circular link to itself
        } else {
            node* curr = head;
            while (curr->next != head) {
                curr = curr->next;
            }
            curr->next = n;
            n->next = head;  // Circular link to head
        }
    }
    void InsertAfterValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            head = n;
            head->next = head;
        } else {
            node* curr = head;
            do {
                if (curr->data == value) {
                    n->next = curr->next;
                    curr->next = n;
                    break;
                }
                curr = curr->next;
            } while (curr != head);
        }
    }
    void InsertBeforeValue(const int value, const int insertingValue) {
        node* n = new node(insertingValue);
        if (head == NULL) {
            head = n;
            head->next = head;
        } else {
            node* curr = head;
            node* prev = NULL;
            do {
                if (curr->data == value) {
                    if (prev == NULL) {  // Insert before head
                        node* tail = head;
                        while (tail->next != head) {
                            tail = tail->next;
                        }
                        n->next = head;
                        tail->next = n;
                        head = n;
                    } else {
                        n->next = curr;
                        prev->next = n;
                    }
                    break;
                }
                prev = curr;
                curr = curr->next;
            } while (curr != head);
        }
    }

    int numNodes() {
        if (head == NULL) return 0;
        int nodes = 0;
        node* curr = head;
        do {
            nodes++;
            curr = curr->next;
        } while (curr != head);
        return nodes;
    }

    void deleteFromHead() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
        } else {
            node* curr = head;
            while (curr->next != head) {  // Find the last node
                curr = curr->next;
            }
            node* temp = head;
            head = head->next;  // Move head
            curr->next = head;  // Update last node's next to new head
            delete temp;
        }
    }

    void deleteFromTail() {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->next == head) {  // Single node case
            delete head;
            head = NULL;
        } else {
            node* curr = head;
            node* prev = NULL;
            while (curr->next != head) {
                prev = curr;
                curr = curr->next;
            }
            prev->next = head;  // Update last node to point to head
            delete curr;
        }
    }

    void deleteValue(const int value) {
        if (head == NULL) {
            cout << "Linked list is empty" << endl;
            return;
        }
        if (head->data == value && head->next == head) {  // Single node case
            delete head;
            head = NULL;
            return;
        }
        node* curr = head;
        node* prev = NULL;
        do {
            if (curr->data == value) {
                if (prev == NULL) {  // Deleting head
                    node* tail = head;
                    while (tail->next != head) {
                        tail = tail->next;
                    }
                    node* temp = head;
                    head = head->next;
                    tail->next = head;
                    delete temp;
                } else {
                    prev->next = curr->next;
                    delete curr;
                }
                return;
            }
            prev = curr;
            curr = curr->next;
        } while (curr != head);
    }

    void printList() {
        if (head == NULL) {
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
    CSLL list;
    
    // Inserting elements at the front
    list.insertAtFront(10);
    list.insertAtFront(20);
    list.insertAtFront(30);
    cout << "After inserting at front:" << endl;
    list.printList();
    
    // Inserting elements at the back
    list.insertAtTail(40);
    list.insertAtTail(50);
    list.insertAtTail(60);
    cout << "After inserting at tail:" << endl;
    list.printList();
    
    cout << "Total nodes in list: " << list.numNodes() << endl;

    // Deleting from head
    list.deleteFromHead();
    cout << "After deleting from head:" << endl;
    list.printList();

    // Deleting from tail
    list.deleteFromTail();
    cout << "After deleting from tail:" << endl;
    list.printList();

    // Deleting a value
    list.deleteValue(40);
    cout << "After deleting value 40:" << endl;
    list.printList();

    // Insert after a specific value
    list.InsertAfterValue(20, 11);
    cout << "Inserted value 11 after 20:" << endl;
    list.printList();

    // Insert before a specific value
    list.InsertBeforeValue(50, 22);
    cout << "Inserted value 22 before 50:" << endl;
    list.printList();

    return 0;
}
