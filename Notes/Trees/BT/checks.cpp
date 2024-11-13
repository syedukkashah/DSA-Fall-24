#include "iostream"
#include "queue"
using namespace std;
class Node{
    public:
    int data;
    Node *right, *left;
    Node(int d):data(d), right(NULL), left(NULL){}
    friend class BT;
};
class BT{
    Node* root;
    public:
    BT():root(NULL){}
    void addNode(int d){ 
    queue<Node*> q; 
    Node* n = new Node(d);
        if(!root) root = n;
        else{
                q.push(root); 
                while(!q.empty())
                {
                    Node* curr = q.front(); 
                    q.pop();
                    if(!curr->left){ 
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
   
    void levelOrder()
    {
        queue<Node*> q;
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

bool isIdentical(Node* r1, Node* r2)
{
    if(!r1 && !r2) return true;
    if((!r1 && r2)||(r1 && !r2)) return false;
    if(r1->data != r2->data) return false;
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right);
}
int main(){
    BT tree, tree2;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(10);
    tree.addNode(50);
    tree.addNode(51);

    tree2.addNode(1);
    tree2.addNode(2);
    tree2.addNode(3);
    tree2.addNode(4);
    tree2.addNode(5);
    tree2.addNode(10);
    tree2.addNode(50);
    tree2.addNode(51); 
    
    cout<<isIdentical(tree.getRoot(), tree2.getRoot());
    return 0;

}
