#include <iostream>
#include <vector>

using namespace std;

class HashTable {
        vector<int> table; 
        int tableSize;
        int hash1(int key) {
            return key % tableSize;
        }
        int hash2(int key) {
            return 1 + (key % (tableSize - 1)); 
        }
    public:
        HashTable(int size) : tableSize(size), table(size, -1) {}
        // Insert a key into the hash table
        void insert(int key) {
            int index = hash1(key); // First hash
            int step = hash2(key); // Second hash

            int i = 0;
            while (table[index] != -1 && table[index] != -2 && i < tableSize) { // -2 indicates deleted
                index = (index + step) % tableSize; // Move to the next index using double hashing
                i++;
            }

            if (i == tableSize) {
                cout << "Hash table is full. Could not insert key: " << key << endl;
                return;
            }

            table[index] = key;
        }

        // Search for a key in the hash table
        bool search(int key) {
            int index = hash1(key);
            int step = hash2(key);

            int i = 0;
            while (table[index] != -1 && i < tableSize) { // Stop at empty slots
                if (table[index] == key) {
                    return true; // Key found
                }
                index = (index + step) % tableSize;
                i++;
            }

            return false; // Key not found
        }

        // Remove a key from the hash table
        void remove(int key) {
            int index = hash1(key);
            int step = hash2(key);

            int i = 0;
            while (table[index] != -1 && i < tableSize) { // Stop at empty slots
                if (table[index] == key) {
                    table[index] = -2; // Mark as deleted
                    cout << "Key " << key << " removed from the hash table.\n";
                    return;
                }
                index = (index + step) % tableSize;
                i++;
            }

            cout << "Key " << key << " not found in the hash table.\n";
        }

        // Display the hash table
        void display() {
            cout << "Hash table:\n";
            for (int i = 0; i < tableSize; i++) {
                cout << i << " -> ";
                if (table[i] == -1) {
                    cout << "NULL";
                } else if (table[i] == -2) {
                    cout << "DELETED";
                } else {
                    cout << table[i];
                }
                cout << "\n";
            }
        }
};

int main() {
    HashTable ht(7); // Create a hash table with 7 slots

    ht.insert(10);
    ht.insert(20);
    ht.insert(15);
    ht.insert(7);
    ht.insert(3);

    ht.display();

    cout << "\nSearching for key 15: " << (ht.search(15) ? "Found" : "Not Found") << "\n";
    cout << "Searching for key 99: " << (ht.search(99) ? "Found" : "Not Found") << "\n";

    ht.remove(15);
    ht.display();

    return 0;
}
