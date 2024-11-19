#include "iostream"
#include "queue"
#include "stack"
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
    void createMirror(Node* r) //inverts the tree nodes (left node becomes right node)
    { 
        if(!r) return;
        //simply swap left and right nodes
        Node* temp = r->right; 
        r->right = r->left;
        r->left = temp;
        //call function recursively for left & right sub-trees
        createMirror(r->right);
        createMirror(r->left);
    }

    int height(Node* r, bool& valid)
    {
        if(!r) return 0;
        int left = height(r->left, valid);
        int right = height(r->right, valid);
        if(abs(left-right)>1) valid = false; //if the mod of difference exceeds 1 it means the node is not balanced, so the bool var is changed to false
        return 1+max(left, right);
    }
    bool isBalanced(Node* r) //make a height helper function ^ to check if tree is balanced
    {
        bool valid = true; //bool variable will be updated inside height function if node is unbalanced
        height(r, valid);
        return valid; 
    }

    bool parent(Node* r, int a, int b) //this function checks if a node has children with the given values
    {
        if(!r) return false;
        if(r->left && r->right)
        {
            if(r->left->data == a && r->right->data == b) return true;
            if(r->right->data == a && r->left->data == b) return true;
        }
        return parent(r->left,a,b) || parent(r->right,a,b); //we call function recursively ro check if the two nodes have the same parent in either the right ot left sub tree
    }

    bool isCousin(Node* r, int a, int b) //nodes must be at the same level with different parents
    {

        //first we check levels of both nodes
        queue<Node*> q;
        q.push(r);
        int l1 = -1, l2 = -1, level = 0;
        while(!q.empty())
        {
            int n = q.size();
            while(n--)
            {
                Node* temp = q.front();
                q.pop();
                //record level of nodes if they're found
                if(temp->data == a) l1 = level; 
                if(temp->data == b) l2 = level;
                //push children into the queue
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
            level++; //when n is 0, the level increases if(l1!=l2) return false; //if levels of the two nodes are not same return falseif(l1!=l2) return false; //if levels of the two nodes are not same return false
            if(l1!=-1 && l2!=-1) break; //means both levels have been found
        }
        return !parent(r, a, b); //if different parents then nodes are cousins
    }
};
bool isIdentical(Node* r1, Node* r2) //function checks if two trees are identical 
{
    if(!r1 && !r2) return true; //if max depth leaf has been reached on both trees, it means this condition was reached without false being returned so tree is identical
    if((!r1 && r2)||(r1 && !r2)) return false; //if nodes don't exist on both trees, return false
    if(r1->data != r2->data) return false; //if data doesn't match return false
    return isIdentical(r1->left, r2->left) && isIdentical(r1->right, r2->right); //traverse both subtrees
}
bool isSubTree(Node* r1, Node* r2) //function checks if a tree is a sub tree of another tree
{
    if(!r1) return false; //This line handles the case when r1 is exhausted (empty), but r2 still has nodes to match, so it's not a subtree.
    if(!r2) return true; //if the second tree is NULL (or empty), then it is considered a subtree of the first tree, therefore true is returned.
    if(isIdentical(r1, r2)) return true;
    return isSubTree(r1->left, r2) || (r1->right, r2); //function is called recursively to check if one tree is identical to any subtree of another tree 
}
bool isMirror(Node* r1, Node* r2) //checks if two trees mirror each other
{
    if(!r1 && !r2) return true;
    if((!r1 && r2)||(r1 && !r2)) return false;
    if(r1->data != r2->data) return false;
    return isMirror(r1->left, r2->right) && isMirror(r1->right, r2->left); //we call the function recursively by seeing if opposite side nodes are identical
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

    cout<<tree.isBalanced(tree.getRoot())<<endl;

    cout<<tree.isCousin(tree.getRoot(), 4,10)<<endl;

    tree2.addNode(1);
    tree2.addNode(2);
    tree2.addNode(3);
    tree2.addNode(4);
    tree2.addNode(5);
    tree2.addNode(10);
    tree2.addNode(50);
    tree2.addNode(51);

/*    tree2 structure:
              1
            /   \
           2     3
          / \   / \
         4   5 10  50
        /
       51  
*/
    cout<<isIdentical(tree.getRoot(), tree2.getRoot())<<endl;

    tree.createMirror(tree.getRoot());
    tree.levelOrder();
    cout<<endl;

    tree2.levelOrder();
    cout<<endl;

    cout<<isMirror(tree.getRoot(), tree2.getRoot())<<endl;

    return 0;
}
