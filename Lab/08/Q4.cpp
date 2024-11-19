#include "iostream"
#include "stack"
#include "vector"
#include "queue"
using namespace std;
class Node{
    public:
    int data;
    Node* left, *right;
    Node(int data):data(data), left(NULL), right(NULL){}
    friend class BT;
};
class BT{
    public:
    Node* root;
    BT():root(NULL){}
    void addNode(int d)
    {
        Node* n = new Node(d);
        if(!root) root = n;
        else{
            queue<Node*> q;
            q.push(root);
            while(!q.empty()){
                Node* curr = q.front();
                q.pop();
                if(!curr->left){
                    curr->left = n;
                    return;
                }
                else q.push(curr->left);
                if(!curr->right){
                    curr->right = n;
                    return;
                }
                else q.push(curr->right);
            }
        }
    }
   
    
    Node* getRoot() const{return root;}
};
bool isIdentical(Node* r1, Node* r2)
    {
        if(!r1 && !r2) return true;
        if((r1&&!r2)||(!r1&&r2)) return false;
        if(r1->data != r2->data) return false;
        return isIdentical(r1->left, r2->left) && (r1->right, r2->right);
    }
    bool isSubTree(Node* r1, Node* r2)
    {
        if(!r1) return false; 
        if(!r2) return true;
        if(isIdentical(r1, r2)) return true;
        return isSubTree(r1->left, r2) || (r1->right, r2);
    }
int main()
{
    BT tree;
    tree.addNode(1);
    tree.addNode(2);
    tree.addNode(3);
    tree.addNode(4);
    tree.addNode(5);
    tree.addNode(6);
    tree.addNode(7);
    tree.addNode(8);

/* 
tree structure:
        1
      /   \
     2     3
    / \   / \
   4   5 6   7
  /
 8  
*/
 BT tree2;
 tree2.addNode(3);
 tree2.addNode(6);
 tree2.addNode(7);
 /*
 tree 2 structure:
     3
    / \
   6   7
 */

    if(isSubTree(tree.getRoot(), tree2.getRoot()))cout<<"T2 is subtree of T1";
    else cout<<"not a subtree";
    return 0;
}
