#include <iostream>
using namespace std;

class Node {
    int val, height;
    Node* left, *right;
public:
    Node(int v) : val(v), height(1), left(NULL), right(NULL) {}

    friend class AVL;
};

class AVL {
public:
    Node* root;
    AVL() : root(NULL) {}

    int getHeight(Node* r) {
        if (!r) return 0;
        return r->height;
    }

    int getBalance(Node* r) {
        if (!r) return 0;
        return getHeight(r->left) - getHeight(r->right);
    }

    Node* rightRotation(Node* r) {
        Node* child = r->left;
        Node* childRight = child->right;

        // Perform rotation
        child->right = r;
        r->left = childRight;

        // Update heights
        r->height = 1 + max(r->left->height, r->right->height);
        child->height = 1 + max(child->left->height, child->right->height);

        return child; // Return new root
    }

    Node* leftRotation(Node* r) {
        Node* child = r->right;
        Node* childLeft = child->left;

        // Perform rotation
        child->left = r;
        r->right = childLeft;

        // Update heights
        r->height = 1 + max(r->left->height, r->right->height);
        child->height = 1 + max(child->left->height, child->right->height);

        return child; // Return new root
    }

    Node* insert(Node* r, int d) {
        if (!r) return new Node(d);
        if (d < r->val) r->left = insert(r->left, d);
        else if (d > r->val) r->right = insert(r->right, d);
        else return r; // Duplicate values not allowed

        // Update height
        r->height = 1 + max(r->left->height, r->right->height);

        // Check balance
        int balance = getBalance(r);

        // LL Case
        if (balance > 1 && d < r->left->val) return rightRotation(r);

        // LR Case
        if (balance > 1 && d > r->left->val) {
            r->left = leftRotation(r->left);
            return rightRotation(r);
        }

        // RR Case
        if (balance < -1 && d > r->right->val) return leftRotation(r);

        // RL Case
        if (balance < -1 && d < r->right->val) {
            r->right = rightRotation(r->right);
            return leftRotation(r);
        }

        // No unbalancing
        return r;
    }
    void preOrder(Node* r) { // NLR
        if (r) {
            cout << r->val << " ";
            preOrder(r->left);
            preOrder(r->right);
        }
    }
};

int main() {
    AVL tree;
    tree.root = tree.insert(tree.root, 10);
    tree.root = tree.insert(tree.root, 20);
    tree.root = tree.insert(tree.root, 30);
    tree.root = tree.insert(tree.root, 50);
    tree.root = tree.insert(tree.root, 70);
    tree.root = tree.insert(tree.root, 5);
    tree.root = tree.insert(tree.root, 100);
    tree.root = tree.insert(tree.root, 95);
    cout << "Pre-order traversal of the AVL tree: ";
    tree.preOrder(tree.root);
    cout << endl;
    return 0;
}
