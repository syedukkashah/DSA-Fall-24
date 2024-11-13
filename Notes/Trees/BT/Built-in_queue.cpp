#include "iostream"
#include "queue"
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
                    Node* curr = q.front(); //save front of queue before poping
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
    return 0;

}
