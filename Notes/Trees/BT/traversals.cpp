#include "iostream"
#include "queue"
#include "stack"
#include "vector"
using namespace std;
class Node{
    public:
    int data;
    Node *right, *left, *next;
    Node(int d):data(d), right(NULL), left(NULL), next(NULL){}
    friend class BT;
};
class BT{
    Node* root;
    queue<Node*> q;
    public:
    BT():root(NULL){}
    void addNode(int d){
        Node* n = new Node(d);
        if(!root) root = n;
        else{
                q.push(root); 
                while(!q.empty())
                {
                    Node* curr = q.front(); //save front of queue before popping
                    q.pop();
                    if(!curr->left){ //if there is no left child, we insert node
                        curr->left = n;
                        return;
                    }
                    else q.push(curr->left); //if left child existed we push it
                    if(!curr->right) //if there is no right child, we insert node
                    {
                        curr->right = n;
                        return;
                    }
                    else q.push(curr->right); //if right child existed then we push it
            }
        }
    }
    Node* getRoot(){return root;}
    void inOrder(Node* r) //LNR
    {
        if(r)
        {
            inOrder(r->left);
            cout<<r->data<<" ";
            inOrder(r->right);
        }
        
    }
    void preOrder(Node* r) //NLR
    {
        if(r)
        {
            cout<<r->data<<" ";
            preOrder(r->left);
            preOrder(r->right);
        }
        
    }
    void postOrder(Node* r) //LRN
    {
        if(r)
        {
            postOrder(r->left);
            postOrder(r->right);
            cout<<r->data<<" ";
        }
    }
    void levelOrder()
    {
        queue<Node*> q; //since queue may not always be empty, we will declare a new one here
        q.push(root);
        while(!q.empty())
        {
            Node* n = q.front();
            cout<<q.front()->data<<" ";
            q.pop();
            if(n->left) q.push(n->left);
            if(n->right)q.push(n->right);
        }
    }
    vector<int> zigzag (Node* r) //spiral level order traversal
    {
        //we use stacks to print elements in zigzag order since a stack reverses elements when popped (Last in First out)
        stack <Node*> s1, s2; //we will use 2 stacks, one that stores elements for L to R printing and vice versa.
        s1.push(r);
        vector<int> spiral; //this vector stores the node values that we will use to print
        while(!s1.empty()||!s2.empty())
        {
            if(!s1.empty()) //Right to Left (We will use s2 for left to right)
            {
                while(!s1.empty()) 
                {
                    Node* temp = s1.top(); //we extract the first element in the stack first
                    s1.pop(); 
                    spiral.push_back(temp->data);
                    /*we push children of current node into the 2nd stack.
                      Since we know we will switch directions in the next level and
                      children are present in the next level, we will push elements in
                      the 2nd stack */ 
                    if(temp->right) s2.push(temp->right); //since s2 us used for LR traversal we push the left child in first since it will reverse the order when popped
                    if(temp->left) s2.push(temp->left);
                }
            }
            else //we use s1 for right to left
            {
                while(!s2.empty())
                {
                    Node* temp = s2.top();
                    s2.pop();
                    spiral.push_back(temp->data);
                    if(temp->left) s1.push(temp->left); //LIFO so left child pushed first for right to left traversal
                    if(temp->right) s1.push(temp->right); 
                }
            }
        }
        return spiral;
    }
};
int main(){
    BT tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(10);
    tree.addNode(50);
    tree.inOrder(tree.getRoot());
    cout<<endl;
    tree.postOrder(tree.getRoot());
    cout<<endl;
    tree.preOrder(tree.getRoot());
    cout<<endl;
    tree.levelOrder();
    cout<<endl;
    vector <int> ZZ = tree.zigzag(tree.getRoot());
    for(int i: ZZ) cout<<i<<" ";
    return 0;
}
