/*
Syed Ukkashah Ahmed Shah
23K-0055
BS(AI) 3-A

Since the code is complex, I have added comments where I felt suitable
*/

#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <chrono> //provides high res clock functionalities
#include <cstdlib>
using namespace std;
using namespace std::chrono;

class BST_Node {
public:
    int ID;
    string name;
    int age;
    BST_Node* left;
    BST_Node* right;

    BST_Node(int id, string n, int a) : ID(id), name(n), age(a), left(NULL), right(NULL) {}
};

class BST {
private:
    BST_Node* root;
    static int idCounter; //static counter for generating unique IDs

    BST_Node* insert(BST_Node* node, int id, string name, int age) {
        if (!node)
            return new BST_Node(id, name, age);
        if (id < node->ID)
            node->left = insert(node->left, id, name, age);
        else if (id > node->ID)
            node->right = insert(node->right, id, name, age);
        return node;
    }

    BST_Node* search(BST_Node* node, int id) {
        if (!node || node->ID == id)
            return node;
        if (id < node->ID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    BST_Node* findMin(BST_Node* node) {
        while (node && node->left)
            node = node->left;
        return node;
    }

    BST_Node* deleteNode(BST_Node* node, int id) {
        if (!node)
            return nullptr;

        if (id < node->ID) {
            node->left = deleteNode(node->left, id);
        } else if (id > node->ID) {
            node->right = deleteNode(node->right, id);
        } else {
            if (!node->left) {
                BST_Node* temp = node->right;
                delete node;
                return temp;
            } else if (!node->right) {
                BST_Node* temp = node->left;
                delete node;
                return temp;
            }

            BST_Node* temp = findMin(node->right);
            node->ID = temp->ID;
            node->name = temp->name;
            node->age = temp->age;
            node->right = deleteNode(node->right, temp->ID);
        }
        return node;
    }

    void inorder(BST_Node* node) {
        if (node) {
            inorder(node->left);
            cout << "ID: " << node->ID << ", Name: " << node->name << ", Age: " << node->age << endl;
            inorder(node->right);
        }
    }

public:
    BST() : root(NULL) {}

    void insert(string name, int age) {
        root = insert(root, ++idCounter, name, age); //generating a unique ID
    }

    void search(int id) {
        BST_Node *result = search(root, id);
        if (result) {
            cout << "Search successful: " << result->name << ", " << result->age << "\n";
        } else {
            cout << "Search failed.\n";
        }
    }

    bool update(int id, string newName, int newAge) {
        BST_Node* node = search(root, id);
        if (node) {
            node->name = newName;
            node->age = newAge;
            return true;
        }
        return false; // ID not found
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};

//Initializing the static ID counter
int BST::idCounter = 0;

class AVL_Node {
public:
    int ID;
    string name;
    int age;
    int height;
    AVL_Node* left;
    AVL_Node* right;

    AVL_Node(int id, string n, int a)
        : ID(id), name(n), age(a), height(1), left(NULL), right(NULL) {}
};

class AVL_Tree {
private:
    AVL_Node* root;
    static int idCounter; //static counter for unique IDs

    int height(AVL_Node* node) {
        return node ? node->height : 0;
    }

    int getBalance(AVL_Node* node) {
        return node ? height(node->left) - height(node->right) : 0;
    }

    AVL_Node* rotateRight(AVL_Node* y) {
        AVL_Node* x = y->left;
        AVL_Node* T2 = x->right;

        x->right = y;
        y->left = T2;

        y->height = max(height(y->left), height(y->right)) + 1;
        x->height = max(height(x->left), height(x->right)) + 1;

        return x;
    }

    AVL_Node* rotateLeft(AVL_Node* x) {
        AVL_Node* y = x->right;
        AVL_Node* T2 = y->left;

        y->left = x;
        x->right = T2;

        x->height = max(height(x->left), height(x->right)) + 1;
        y->height = max(height(y->left), height(y->right)) + 1;

        return y;
    }

    AVL_Node* insert(AVL_Node* node, int id, string name, int age) {
        if (!node)
            return new AVL_Node(id, name, age);

        if (id < node->ID)
            node->left = insert(node->left, id, name, age);
        else if (id > node->ID)
            node->right = insert(node->right, id, name, age);
        else
            return node; //duplicate IDs not allowed

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        //balancing the tree
        if (balance > 1 && id < node->left->ID)
            return rotateRight(node);

        if (balance < -1 && id > node->right->ID)
            return rotateLeft(node);

        if (balance > 1 && id > node->left->ID) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && id < node->right->ID) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }

    AVL_Node* search(AVL_Node* node, int id) {
        if (!node || node->ID == id)
            return node;
        if (id < node->ID)
            return search(node->left, id);
        else
            return search(node->right, id);
    }

    AVL_Node* findMin(AVL_Node* node) {
        while (node->left)
            node = node->left;
        return node;
    }

    AVL_Node* deleteNode(AVL_Node* node, int id) {
        if (!node)
            return node;

        if (id < node->ID)
            node->left = deleteNode(node->left, id);
        else if (id > node->ID)
            node->right = deleteNode(node->right, id);
        else {
            if (!node->left || !node->right) {
                AVL_Node* temp = node->left ? node->left : node->right;
                delete node;
                return temp;
            } else {
                AVL_Node* temp = findMin(node->right);
                node->ID = temp->ID;
                node->name = temp->name;
                node->age = temp->age;
                node->right = deleteNode(node->right, temp->ID);
            }
        }

        node->height = max(height(node->left), height(node->right)) + 1;
        int balance = getBalance(node);

        if (balance > 1 && getBalance(node->left) >= 0)
            return rotateRight(node);

        if (balance > 1 && getBalance(node->left) < 0) {
            node->left = rotateLeft(node->left);
            return rotateRight(node);
        }

        if (balance < -1 && getBalance(node->right) <= 0)
            return rotateLeft(node);

        if (balance < -1 && getBalance(node->right) > 0) {
            node->right = rotateRight(node->right);
            return rotateLeft(node);
        }

        return node;
    }
    void inorder(AVL_Node* node) {
        if (node) {
            inorder(node->left);
            cout << "ID: " << node->ID << ", Name: " << node->name << ", Age: " << node->age << endl;
            inorder(node->right);
        }
    }

public:
    AVL_Tree() : root(NULL) {}

    void insert(string name, int age) {
        root = insert(root, ++idCounter, name, age);
    }

    void search(int id) {
        AVL_Node* result = search(root, id);
        if (result) {
            cout << "Search successful: " << result->name << ", " << result->age << "\n";
        } else {
            cout << "Search failed.\n";
        }
    }

    //updating a record
    bool update(int id, string newName, int newAge) {
        AVL_Node* node = search(root, id);
        if (node) {
            node->name = newName;
            node->age = newAge;
            return true;
        }
        return false; //record not found
    }

    void deleteNode(int id) {
        root = deleteNode(root, id);
    }

    void display() {
        inorder(root);
        cout << endl;
    }
};
//initializing the static ID counter
int AVL_Tree::idCounter = 0;

class BTreeTable {
public:
    int ID;
    string name;
    int age;

    BTreeTable() {}

    BTreeTable(int id, string n, int a) {
        ID = id;
        name = n;
        age = a;
    }
};

class BTreeNode {
    BTreeTable *keys;   
    int t;              //minimum degree
    BTreeNode **C;      //array of child pointers
    int n;              //number of keys in the node
    bool leaf;          //true if node is a leaf

public:
    BTreeNode(int _t, bool _leaf) {
        t = _t;
        leaf = _leaf;
        keys = new BTreeTable[2 * t - 1];
        C = new BTreeNode *[2 * t];
        n = 0;
    }

    void traverse() {
        int i;
        for (i = 0; i < n; i++) {
            if (!leaf)
                C[i]->traverse();
            cout << "ID: " << keys[i].ID << ", Name: " << keys[i].name << ", Age: " << keys[i].age << endl;
        }
        if (!leaf)
            C[i]->traverse();
    }

    BTreeNode *search(int id) {
        int i = 0;
        while (i < n && id > keys[i].ID)
            i++;

        if (i < n && keys[i].ID == id)
            return this;

        if (leaf)
            return NULL;

        return C[i]->search(id);
    }

    int findKey(int id) {
        int idx = 0;
        while (idx < n && keys[idx].ID < id)
            ++idx;
        return idx;
    }

    void insertNonFull(int id, string na, int a) {
        int i = n - 1;

        if (leaf) {
            while (i >= 0 && keys[i].ID > id) {
                keys[i + 1] = keys[i];
                i--;
            }
            keys[i + 1].ID = id;
            keys[i + 1].name = na;
            keys[i + 1].age = a;
            n++;
        } else {
            while (i >= 0 && keys[i].ID > id)
                i--;

            if (C[i + 1]->n == 2 * t - 1) {
                splitChild(i + 1, C[i + 1]);
                if (keys[i + 1].ID < id)
                    i++;
            }
            C[i + 1]->insertNonFull(id, na, a);
        }
    }

    void splitChild(int i, BTreeNode *y) {
        BTreeNode *z = new BTreeNode(y->t, y->leaf);
        z->n = t - 1;

        for (int j = 0; j < t - 1; j++)
            z->keys[j] = y->keys[j + t];

        if (!y->leaf) {
            for (int j = 0; j < t; j++)
                z->C[j] = y->C[j + t];
        }

        y->n = t - 1;

        for (int j = n; j >= i + 1; j--)
            C[j + 1] = C[j];

        C[i + 1] = z;

        for (int j = n - 1; j >= i; j--)
            keys[j + 1] = keys[j];

        keys[i] = y->keys[t - 1];
        n++;
    }

    void deletion(int id) {
        int idx = findKey(id);

        if (idx < n && keys[idx].ID == id) {
            if (leaf)
                removeFromLeaf(idx);
            else
                removeFromNonLeaf(idx);
        } else {
            if (leaf) {
                cout << "The key " << id << " is not in the tree\n";
                return;
            }

            bool flag = (idx == n);

            if (C[idx]->n < t)
                fill(idx);

            if (flag && idx > n)
                C[idx - 1]->deletion(id);
            else
                C[idx]->deletion(id);
        }
    }

    void removeFromLeaf(int idx) {
        for (int i = idx + 1; i < n; i++)
            keys[i - 1] = keys[i];
        n--;
    }

    void removeFromNonLeaf(int idx) {
        int id = keys[idx].ID;

        if (C[idx]->n >= t) {
            int pred = getPredecessor(idx);
            keys[idx].ID = pred;
            C[idx]->deletion(pred);
        } else if (C[idx + 1]->n >= t) {
            int succ = getSuccessor(idx);
            keys[idx].ID = succ;
            C[idx + 1]->deletion(succ);
        } else {
            merge(idx);
            C[idx]->deletion(id);
        }    
    }

    int getPredecessor(int idx) {
        BTreeNode *cur = C[idx];
        while (!cur->leaf)
            cur = cur->C[cur->n];
        return cur->keys[cur->n - 1].ID;
    }

    int getSuccessor(int idx) {
        BTreeNode *cur = C[idx + 1];
        while (!cur->leaf)
            cur = cur->C[0];
        return cur->keys[0].ID;
    }

    //filling a child
    void fill(int idx) {
        if (idx != 0 && C[idx - 1]->n >= t)
            borrowFromPrev(idx);
        else if (idx != n && C[idx + 1]->n >= t)
            borrowFromNext(idx);
        else {
            if (idx != n)
                merge(idx);
            else
                merge(idx - 1);
        }
    }

    //borrow from the previous sibling
    void borrowFromPrev(int idx) {
        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx - 1];

        for (int i = child->n - 1; i >= 0; --i)
            child->keys[i + 1] = child->keys[i];

        if (!child->leaf) {
            for (int i = child->n; i >= 0; --i)
                child->C[i + 1] = child->C[i];
        }

        child->keys[0] = keys[idx - 1];

        if (!child->leaf)
            child->C[0] = sibling->C[sibling->n];

        keys[idx - 1] = sibling->keys[sibling->n - 1];

        child->n += 1;
        sibling->n -= 1;
    }

    //borrow from the next sibling
    void borrowFromNext(int idx) {
        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx + 1];
        child->keys[child->n] = keys[idx];

        if (!child->leaf)
            child->C[child->n + 1] = sibling->C[0];

        keys[idx] = sibling->keys[0];

        for (int i = 1; i < sibling->n; ++i)
            sibling->keys[i - 1] = sibling->keys[i];

        if (!sibling->leaf) {
            for (int i = 1; i <= sibling->n; ++i)
                sibling->C[i - 1] = sibling->C[i];
        }

        child->n += 1;
        sibling->n -= 1;
    }

    //merge two children
    void merge(int idx) {
        BTreeNode *child = C[idx];
        BTreeNode *sibling = C[idx + 1];

        child->keys[t - 1] = keys[idx];

        for (int i = 0; i < sibling->n; ++i)
            child->keys[i + t] = sibling->keys[i];

        if (!child->leaf) {
            for (int i = 0; i <= sibling->n; ++i)
                child->C[i + t] = sibling->C[i];
        }

        for (int i = idx + 1; i < n; ++i)
            keys[i - 1] = keys[i];

        for (int i = idx + 2; i <= n; ++i)
            C[i - 1] = C[i];

        child->n += sibling->n + 1;
        n--;

        delete sibling;
    }

    friend class BTree;
};

class BTree {
    BTreeNode *root; //pointer to root node
    int t;           //minimum degree
    static int idCounter;

public:
    BTree(int _t):t(_t), root(NULL){} 
    void traverse() {
        if (root != NULL)
            root->traverse();
    }

    void search(int k) {
        if(root == NULL) return;
        BTreeNode *found = root->search(k);
        if (found) {
            int index = found->findKey(k);
            cout << "Search successful: " << found->keys[index].name << ", " << found->keys[index].age << "\n";
        } else {
            cout << "Search failed.\n";
        }
    }

    //updating record
    bool update(int id, string newName, int newAge) {
        BTreeNode* node = root->search(id);
        if (node) {
            int index = node->findKey(id);
            node->keys[index].name = newName;
            node->keys[index].age = newAge;
            return true;
        }
        return false; //record not found
    }

    void insert(string na, int a) {
        int id = ++idCounter;
        if (root == NULL) {
            root = new BTreeNode(t, true);
            root->keys[0].ID = id;
            root->keys[0].name = na;
            root->keys[0].age = a;
            root->n = 1;
        } else {
            if (root->n == 2 * t - 1) {
                BTreeNode *s = new BTreeNode(t, false);
                s->C[0] = root;
                s->splitChild(0, root);
                int i = 0;
                if (s->keys[0].ID < id)
                    i++;
                s->C[i]->insertNonFull(id, na, a);
                root = s;
            } else {
                root->insertNonFull(id, na, a);
            }
        }
    }

    void deletion(int k) {
        if (!root) {
            cout << "The tree is empty\n";
            return;
        }

        root->deletion(k);

        if (root->n == 0) {
            BTreeNode *tmp = root;
            if (root->leaf)
                root = NULL;
            else
                root = root->C[0];
            delete tmp;
        }
    }
};

int BTree::idCounter = 0;

void generateDummyData(BST &bst, AVL_Tree &avl, BTree &btree, int size) {
    auto start = std::chrono::high_resolution_clock::now();
    srand(time(0));
    for(int i=0; i<size; i++) {
        string name = "Aisha" + to_string(i+1);
        int age = rand()%100;
        bst.insert(name, age);
        avl.insert(name, age);
        btree.insert(name, age);
    }
    auto end = std::chrono::high_resolution_clock::now();
    long long timeTaken = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    cout << "Time taken for insertion of same data in all trees: " << timeTaken << endl;
}

//insertion of multiple nodes into the BST and time the operation
void timedInsertBST(BST &tree, int numElements) {
    auto start = high_resolution_clock::now(); //captures the current time point at the start of the operation you want to time. 
    for (int i = 1; i <= numElements; ++i) {
        string name = "Name" + to_string(i);
        int age = rand() % 50 + 20; //random age between 20 and 70
        tree.insert(name, age);
    }
    auto end = high_resolution_clock::now(); //After the operation is complete, another time point is captured using high_resolution_clock::now()
    cout << "Time taken for insertion in BST: "
         << duration_cast<milliseconds>(end - start).count() //converts the duration into milliseconds
         << " milliseconds\n";
}

void timedInsertAVL(AVL_Tree &tree, int numElements) {
    auto start = high_resolution_clock::now();
    for (int i = 1; i <= numElements; ++i) {
        string name = "Name" + to_string(i);
        int age = rand() % 50 + 20; //random age between 20 and 70
        tree.insert(name, age);
    }
    auto end = high_resolution_clock::now();
    cout << "Time taken for insertion in AVL TREE: "
         << duration_cast<milliseconds>(end - start).count()
         << " milliseconds\n";
}

void timedInsertBTREE(BTree &tree, int numElements) {
    auto start = high_resolution_clock::now();
    for (int i = 1; i <= numElements; ++i) {
        string name = "Name" + to_string(i);
        int age = rand() % 50 + 20; 
        tree.insert(name, age);
    }
    auto end = high_resolution_clock::now();
    cout << "Time taken for insertion in B TREE: "
         << duration_cast<milliseconds>(end - start).count()
         << " milliseconds\n";
}

//searching for a specific element and time the operation
void timedSearchBST(BST &tree, int idToSearch) {
    auto start = high_resolution_clock::now();
    tree.search(idToSearch);
    auto end = high_resolution_clock::now();
    cout << "Time taken for search in BST: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedSearchAVL(AVL_Tree &tree, int idToSearch) {
    auto start = high_resolution_clock::now();
    tree.search(idToSearch); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for search in AVL Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedSearchBTREE(BTree &tree, int idToSearch) {
    auto start = high_resolution_clock::now();
    tree.search(idToSearch);
    auto end = high_resolution_clock::now();
    cout << "Time taken for search in B-Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

//deleting a specific element and time the operation
void timedDeleteBST(BST &tree, int idToDelete) {
    auto start = high_resolution_clock::now();
    tree.deleteNode(idToDelete); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for deletion in BST: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedDeleteAVL(AVL_Tree &tree, int idToDelete) {
    auto start = high_resolution_clock::now();
    tree.deleteNode(idToDelete); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for deletion in AVL Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedDeleteBTREE(BTree &tree, int idToDelete) {
    auto start = high_resolution_clock::now();
    tree.deletion(idToDelete); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for deletion in B-Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

//updating a specific element and time the operation
void timedUpdateBST(BST &tree, int idToUpdate, const string &newName, int newAge) {
    auto start = high_resolution_clock::now();
    tree.update(idToUpdate, newName, newAge); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for update in BST: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedUpdateAVL(AVL_Tree &tree, int idToUpdate, const string &newName, int newAge) {
    auto start = high_resolution_clock::now();
    tree.update(idToUpdate, newName, newAge); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for update in AVL Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

void timedUpdateBTREE(BTree &tree, int idToUpdate, const string &newName, int newAge) {
    auto start = high_resolution_clock::now();
    tree.update(idToUpdate, newName, newAge); 
    auto end = high_resolution_clock::now();
    cout << "Time taken for update in B-Tree: "
         << duration_cast<microseconds>(end - start).count()
         << " microseconds\n";
}

int main() {
    BST bstTree;
    AVL_Tree avlTree;
    BTree bTree(3);

    // Predefined data sizes for testing
    int dataSizes[] = {1000, 5000, 10000};

    // Predefined IDs for search, delete, and update operations
    int searchID = 500;    
    int deleteID = 2500;   
    int updateID = 7500;  

    for (int size : dataSizes) {
        cout << "\nInserting " << size << " elements into the trees:" << endl;
        timedInsertBST(bstTree, size);
        timedInsertAVL(avlTree, size);
        timedInsertBTREE(bTree, size);
        cout<<endl;

        cout << "\nSearching for ID " << searchID << ": " << endl;
        timedSearchBST(bstTree, searchID);
        timedSearchAVL(avlTree, searchID);
        timedSearchBTREE(bTree, searchID);
        cout<<endl;

        cout << "\nAttempting to delete ID " << deleteID << ":" << endl;
        timedDeleteBST(bstTree, deleteID);
        timedDeleteAVL(avlTree, deleteID);
        timedDeleteBTREE(bTree, deleteID);
        cout<<endl;

        cout << "\nUpdating the record with ID " << updateID << ":" << endl;
        timedUpdateBST(bstTree, updateID, "UpdatedName", 30);
        timedUpdateAVL(avlTree, updateID, "UpdatedName", 30);
        timedUpdateBTREE(bTree, updateID, "UpdatedName", 30);
        cout<<endl;
    }
    return 0;
}