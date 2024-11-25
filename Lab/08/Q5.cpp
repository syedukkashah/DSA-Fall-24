#include <iostream>
#include <vector>
using namespace std;
class Node
{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data):data(data), left(NULL), right(NULL){}
};
Node* createBSTFromSortedArray(vector<int>& arr, int start, int end)
{
    if (start > end)return NULL;
    int mid = start + (end-start) / 2;
    Node *root = new Node(arr[mid]);
    root->left = createBSTFromSortedArray(arr, start, mid - 1);
    root->right = createBSTFromSortedArray(arr, mid + 1, end);
    return root;
}
void preOrder(Node *node)
{
    if (node != NULL)
    {
        cout << node->data << " ";
        preOrder(node->left);
        preOrder(node->right);
    }
}
int main()
{
    vector<int> arr = {0, 6, 12, 18, 24};
    Node *root = createBSTFromSortedArray(arr, 0, arr.size()-1);
    cout << "BST: ";
    preOrder(root);
    /*
             12
           /    \
          0     18
           \      \
            6      24
    */
    cout << endl;
    return 0;
}
