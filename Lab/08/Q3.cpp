#include "iostream"
#include "stack"
#include "vector"
#include "queue"
using namespace std;
class Node{
    int data;
    Node* left, *right;
    public:
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
    int maxPathSumUtil(Node* r, int& ans)
   {
        if(!r) return 0; //if no path exists then return 0
        //now we will calculate the sum of paths flowing through left & right nodes
        int left = maxPathSumUtil(r->left, ans);
        int right = maxPathSumUtil(r->right, ans);
        //here the strategy has been implemented for (1) & (4) , (2) & (3)
        int nodeMax = max(max(r->data, r->data+left+right), max(r->data+left, r->data+right));
        ans = max(ans, nodeMax); //now we update the pre existing sum val with the nodeMax by comparing the values
        int singlePathSum = max(r->data, max(r->data+left, r->data+right)); // we won't consider  r->data+left+right since it considers path from both subtrees which will form a complete path traversing the whole tree
        return singlePathSum;
   }
   int maxPathSum(Node* r)
   {
        int ans = INT16_MIN;
        maxPathSumUtil(r, ans);
        return ans;
   }
};
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

cout<<tree.maxPathSum(tree.getRoot());
return 0;

}




