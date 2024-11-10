#include "iostream"
#include "queue"
#include "string"
#include "cstdlib"
#include "vector"
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
    vector<vector<int>> zigzag(Node* root){
        queue<Node*> q;
        vector<vector<int>> result;
        if(!root) return result;
        q.push(root);
        bool LR = true;
        while(!q.empty())
        {
            int size = q.size();
            vector<int> row(size);
            for(int i=0; i<size; i++)
            {
                Node* n = q.front();
                q.pop();
                int index = (LR) ? i : (size - 1 - i); //insert at front if left to right traversal is true else insert at back
                row[index] = n->data;
                if(n->left) q.push(n->left);
                if(n->right) q.push(n->right);
            }
            LR = !LR;
            result.push_back(row);
        }
        return result;
    }
    
    Node* getRoot() const{return root;}
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

    vector<vector<int>> zigzag = tree.zigzag(tree.getRoot());
    for(const auto& row: zigzag)
    {
        for (int val:row) cout<<val<<" ";
        cout<<endl;
    }
    return 0;
}
