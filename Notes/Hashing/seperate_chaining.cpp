#include <iostream>
#include <vector>
using namespace std;

class Node {
    int key;
    Node* next;

public:
    Node(int k) : key(k), next(nullptr) {}
    friend class HashTable;
};

class HashTable {
    vector<Node*> table;
    int size;

public:
    HashTable(int s) : size(s), table(s, nullptr) {}

    int hashCode(int key) { return key % size; }

    void insert(int key) {
        int idx = hashCode(key);
        Node* newNode = new Node(key);
        newNode->next = table[idx];
        table[idx] = newNode;
    }

    void remove(int key) {
        int idx = hashCode(key);
        Node* curr = table[idx];
        Node* prev = nullptr;

        while (curr) {
            if (curr->key == key) {
                if (prev == nullptr) { // Key is at the head of the list
                    table[idx] = curr->next;
                } else { // Key is somewhere else in the list
                    prev->next = curr->next;
                }
                delete curr;
                return;
            }
            prev = curr;
            curr = curr->next;
        }

        cout << "Key " << key << " not found\n";
    }

    bool search(int key) {
        int idx = hashCode(key);
        Node* curr = table[idx];
        while (curr) {
            if (curr->key == key) return true;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        for (int i = 0; i < size; i++) {
            cout << "Bucket " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->key << " -> ";
                current = current->next;
            }
            cout << "nullptr\n";
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* curr = table[i];
            while (curr) {
                Node* temp = curr;
                curr = curr->next;
                delete temp;
            }
        }
    }
};

int main() {
    HashTable ht(7); // Create a hash table with 7 buckets

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(3);

    cout << "Initial hash table:\n";
    ht.display();

    cout << "\nSearching for key 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
    cout << "Searching for key 25: " << (ht.search(25) ? "Found" : "Not Found") << "\n";

    ht.remove(15);
    cout << "\nHash table after removing key 15:\n";
    ht.display();

    ht.remove(25); // Attempt to remove a non-existent key
    cout << "\nHash table after attempting to remove key 25:\n";
    ht.display();

    return 0;
}
