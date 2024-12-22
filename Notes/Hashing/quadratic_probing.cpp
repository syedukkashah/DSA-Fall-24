#include "iostream"
#include "vector"
using namespace std;

class DataItem {
    int key, data;
public:
    DataItem(int k, int d) : key(k), data(d) {}
    friend class HashTable;
};

class HashTable {
    int size, curr_size;
    vector<DataItem*> table;
    DataItem* dummy = new DataItem(-1, -1); // Used as a placeholder for deleted entries
    int hashCode(int key) { return key % size; }

public:
    HashTable(int s) : size(s), curr_size(0) {
        table.resize(s, NULL);
    }

    // Insert method
    void insert(int key, int data) {
        if (curr_size == size) {
            cout << "Table full" << endl;
            return;
        }
        int idx = hashCode(key), i = 0;
        DataItem* d = new DataItem(key, data);

        while (table[idx] != NULL && table[idx] != dummy) {
            if (table[idx]->key == key) { // Check for duplicates
                table[idx]->data = data; // Update data of pre-existing key
                delete d;
                return;
            }
            i++;
            idx = (hashCode(key) + i * i) % size; // Quadratic probing
        }
        table[idx] = d;
        curr_size++; // Increment current size
    }

    // Delete method
    void deleteKey(int key) {
        int idx = hashCode(key), i = 0;
        while (table[idx]) {
            if (table[idx]->key ) {
                delete table[idx];
                table[idx] = dummy; // Mark the slot as deleted with a dummy value
                curr_size--; // Decrement table size
                return;
            }
            i++;
            idx=(idx + (i*i))%size; // Quadratic probing
        }
        cout << "Key not found" << endl;
    }
    DataItem* search(int key) {
        int idx = hashCode(key), i = 0;
        int startIdx = idx;
        while (table[idx]) {
            if (table[idx]->key == key && table[idx]!=dummy)return table[idx];         
            i++;
            idx=(idx + (i*i))%size; // Quadratic probing
             // If we've cycled back to the original index, the key doesn't exist
            if (idx == startIdx)break;
            
        }
        return NULL; 
    }


    void display() {
        for (int i = 0; i < size; ++i) {
            if (table[i] != NULL && table[i] != dummy) {
                cout << "(" << table[i]->key << ", " << table[i]->data << ") ";
            } else {
                cout << "~ "; 
            }
        }
        cout << endl;
    }

    ~HashTable() {
        for (DataItem* d : table) {
            if (d != NULL && d != dummy) delete d;
        }
        delete dummy; // Free dummy object
    }
};

int main() {
    HashTable ht(7);

    ht.insert(150, 20);
    ht.insert(245, 70);
    ht.insert(63, 80);
    ht.insert(421, 25);
    ht.insert(82, 44);
    ht.insert(107, 32);
    ht.insert(315, 11);

    ht.display();

    if (ht.search(89)) {
        cout << "Key 89 found" << endl;
    } else {
        cout << "Key 89 not found" << endl;
    }

    if (ht.search(82)) {
        cout << "Key 82 found" << endl;
    } else {
        cout << "Key 82 not found" << endl;
    }

    ht.deleteKey(53); // Key 53 doesn't exist, should print "Key not found"
    ht.deleteKey(107); // Key 107 exists, should be deleted

    ht.display(); // Final state of the table

    return 0;
}
