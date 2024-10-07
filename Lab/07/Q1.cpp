#include <iostream>

struct Node {
    int data;
    Node* next;
    
    Node(int val) : data(val), next(nullptr) {}
};

void swap(Node* a, Node* b) {
    int temp = a->data;
    a->data = b->data;
    b->data = temp;
}

Node* partition(Node* head, Node* end, Node** newHead, Node** newEnd) {
    Node* pivot = end;
    Node* prev = nullptr;
    Node* curr = head;
    Node* tail = pivot; 

    while (curr != pivot) {
        if (curr->data < pivot->data) {
            if (*newHead == nullptr) *newHead = curr; 
            prev = curr; 
            curr = curr->next;
        } else {
          
            if (prev) prev->next = curr->next;
            Node* temp = curr->next;
            curr->next = nullptr;
            tail->next = curr; 
            tail = curr; 
            curr = temp; 
        }
    }

    if (*newHead == nullptr) *newHead = pivot;

    *newEnd = tail;
    return pivot;
}

Node* quickSort(Node* head) {
    if (!head || !head->next) return head; 

    Node* newHead = nullptr;
    Node* newEnd = nullptr;

    Node* pivot = partition(head, head, &newHead, &newEnd);
    
    if (newHead != pivot) {
        Node* temp = newHead;
        while (temp->next != pivot) temp = temp->next;
        temp->next = nullptr; 
        
        newHead = quickSort(newHead); 

        temp = newHead;
        while (temp->next) temp = temp->next; 
        temp->next = pivot;
    }
    pivot->next = quickSort(pivot->next); 
    return newHead; 
}
void printList(Node* head) {
    while (head) {
        std::cout << head->data << " ";
        head = head->next;
    }
    std::cout << std::endl;
}
Node* createLinkedList(int arr[], int size) {
    Node* head = nullptr;
    Node* tail = nullptr;
    
    for (int i = 0; i < size; i++) {
        Node* newNode = new Node(arr[i]);
        if (!head) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }
    
    return head;
}
int main() {
    int arr[] = {10, 7, 8, 9, 1, 5, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    Node* head = createLinkedList(arr, size);
    head = quickSort(head);
    
    std::cout << "Sorted linked list: ";
    printList(head);
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}
