#include "iostream"
#include "queue"
using namespace std;
class Node{
    public:
    Node *left, *right;
    int data;
    Node(int d):data(d), right(NULL), left(NULL){}
    friend class BST;
    friend class BT;
};
class BST{
    public:
    Node* root;
    BST(): root(NULL){}
    Node* insert(int d, Node* r)
    {
        if(!r)
        {
            Node* temp = new Node(d);
            return temp;
        }
        if(d<r->data) r->left = insert(d, r->left);
        if(d>r->data) r->right = insert(d, r->right);
        return r;
    }
};

class BT{
    public:
    Node* root;
    BT(): root(NULL){}
    void insert(int d)
    {
        Node* n = new Node(d);
        if(!root)
        {
            root = n;
            return;
        }
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr = q.front();
            q.pop();
            if(!curr->left)
            {
                curr->left = n;
                return;
            } 
            else q.push(curr->left);
            if(!curr->right)
            {
                curr->right = n;
                return;
            } 
            else q.push(curr->right);
        }
    }
};


//approach 1 to check validity
bool isBST(Node* r)
{
    if(!r) return true; //if all nodes have been traversed then it must be BST
    if(r->left && r->data<r->left->data ||r->right && r->data > r->right->data) return false; 
    return isBST(r->left) && isBST(r->right);
}


void inorder(Node* r, vector<int>& ans) 
    {
        if(!r) return;
        inorder(r->left, ans);
        ans.push_back(r->data);
        inorder(r->right, ans);
    }

//approach 2 to check validity
    bool isValidBST(Node* r) {
        vector<int> ans;
        inorder(r, ans);
        for(int i=1; i<ans.size()-1; i++) if(ans[i]<=ans[i-1]) return false;
        return true;
    }
int main()
{
    BT bt;
    BST bst;

    bt.insert(5);
    bt.insert(1);
    bt.insert(4);
    bt.insert(9);
    bt.insert(6);
    bt.insert(3);
    bt.insert(2);
    bt.insert(7);
    bt.insert(8);

/*  Binary tree structure:

            5
          /   \
         1     4
       /  \   / \
      9    6  3   2
     / \            
    7   8          
*/
    bst.root = bst.insert(5, bst.root);
    bst.root = bst.insert(1, bst.root);
    bst.root = bst.insert(4, bst.root);
    bst.root = bst.insert(9, bst.root);
    bst.root = bst.insert(6, bst.root);
    bst.root = bst.insert(3, bst.root);
    bst.root = bst.insert(2, bst.root);
    bst.root = bst.insert(7, bst.root);
    bst.root = bst.insert(8, bst.root);

/*

   Binary Search Tree structure: 
             5
           /   \
          1     9
           \   / 
           4  6   
           /   \   
          3     7
         /       
        2
*/

cout<<isBST(bt.root)<<endl;
cout<<isBST(bst.root)<<endl;
cout<<isValidBST(bt.root)<<endl;
cout<<isValidBST(bst.root)<<endl;
return 0;
}
