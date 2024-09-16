#include "iostream"
using namespace std;
class Node {
    public:
    int data;
    Node* next;
    Node(int data,  Node* next = nullptr):data(data), next(next){}

};
Node* reverseSLL(Node* head, Node* prev = nullptr) {
    if (head == nullptr) {
        return prev;
    }

    Node* next = head->next;
    head->next = prev;
    prev = head;
    head = next;
    return reverseSLL(head, prev);
}
int main() {
    Node* head = new Node(1, new Node(2, new Node(3, new Node(4, new Node(5)))));

    cout << "Original list: ";
    Node* temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    head = reverseSLL(head);
    cout << "Reversed list: ";
    temp = head;
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return 0;
}
   
