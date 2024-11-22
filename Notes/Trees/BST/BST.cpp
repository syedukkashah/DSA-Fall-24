#include "iostream"
#include "queue"
using namespace std;
class Node{
    int data;
    Node *left, *right;
    public:
    Node(int d):data(d), right(NULL), left(NULL){}
    friend class BST;
};
class BST{
    public:
    Node*  root;
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

    void levelOrder()
    {
        if(!root) return; 
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* curr = q.front();
            cout<<q.front()->data<<" ";
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);        
        }
    }

    void inOrder(Node* r) //returns the node values in ascending order
    {
        if(!r) return;
        inOrder(r->left);
        cout<<r->data<<" ";
        inOrder(r->right);
    }

    bool search(Node* r, int target)
    {
        if(!r) return false; //if all nodes have been traversed and target isn't found
        if(r->data == target) return true;
        if(target < r->data) return search(r->left, target);
        else return search(r->right, target);
    }

    Node* deleteNode (Node* r, int target)
    { 
        if(!r) return NULL; //if target isn't present 
        if(r->data > target) r->left = deleteNode(r->left, target);
        else if(r->data < target) r->right = deleteNode(r->right, target);
        else
        {
            //leaf node
            if(!r->left && !r->right)
            {
                delete r;
                return NULL;
            }

            // one child exists
            if(!r->left && r->right)
            {
                Node* temp = r->right;
                delete r;
                return temp;
            }
            if(r->left && !r->right)
            {
                Node* temp = r->left;
                delete r;
                return r;
            }

            //both children exist
            if(r->left && r->right)
            {
                //find greatest element in left sub-tree (n)
                Node* child = r->left;
                Node* parent = r;

                //to traverse to n
                while(child->right) 
                {
                    parent = child;
                    child = child->right;
                }
                if(r!=parent)
                {
                    parent->right = child->left;
                    child->left = r->left;
                    child->right = r->right;
                    delete r;
                    return child;
                }
                else {
                    child->right = r->right;
                    delete r;
                    return child;
                }

            }


        }
    }

};
int main()
{
    BST tree;
    tree.root = tree.insert(8,tree.root);
    tree.root = tree.insert(4, tree.root);
    tree.root = tree.insert(3, tree.root);
    tree.root = tree.insert(6, tree.root);
    tree.root = tree.insert(11, tree.root);
    tree.root = tree.insert(13, tree.root);
    tree.root = tree.insert(12, tree.root);
    tree.root = tree.insert(5, tree.root);

    /*
        
            8
          /   \
         4     11
       /  \      \
      3    6      13  
           /      /
          5      12
                     
    */
    tree.levelOrder();
    cout<<endl;
    tree.inOrder(tree.root); 
    cout<<endl;
    cout<<tree.search(tree.root, 6)<<endl;
    cout<<tree.search(tree.root, -9)<<endl;
    return 0;
}