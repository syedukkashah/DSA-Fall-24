#include "iostream"
#include "vector"
using namespace std;
class DataItem{
    int key, data;
    public:
    DataItem(int k, int d):key(k), data(d){}
    friend class HashTable;
};
class HashTable{
    int size, curr_size;
    vector<DataItem*> table;
    int hashCode(int key){return key%size;}
    public:
    HashTable(int s):size(s), curr_size(0)
    {
        table.resize(s,NULL);
    }
    void insert(int key, int data)
    {
        int idx = hashCode(key);
        DataItem* d = new DataItem(key, data);
        while(table[idx]) idx = (idx+1)%size; //linear probing
        table[idx] = d;
        curr_size++; //increment curr size
    }
    void deleteKey(int key)
    {
        int idx = hashCode(key);
        while(table[idx])
        {
            if(table[idx]->key == key)
            {
                DataItem* temp = table[idx];
                table[idx] = NULL;
                delete temp;
                curr_size--; //decrement table size
                return;
            }
            idx = (idx+1)%size; //linear probing
        }
    }
    DataItem* search(int key)
    {
        int idx = hashCode(key);
        while(table[idx])
        {
            if(table[idx]->key == key) return table[idx];
            idx = (idx+1)%size;
        }
        return NULL;
    }
    void display()
    {
        for(DataItem* d: table)
        {
            if(d) cout<<"("<<d->key<<","<<d->data<<") ";
            else cout<<" ~ ";
        }
    }
};
int main()
{
    HashTable ht(10);
    ht.insert(1, 20);
    ht.insert(2, 70);
    ht.insert(42, 80);
    ht.insert(4, 25);
    ht.insert(12, 44);
    ht.insert(14, 32);
    ht.insert(17, 11);
    ht.insert(13, 78);
    ht.insert(37, 97);
    ht.display();
    return 0;
}
