#include "iostream"
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
                if(!curr->right){
                    curr->right = n;
                    return;
                }
                else q.push(curr->right);
            }
        }
    }
    void inOrder(Node* root)
    {
        if(!root) return;
        inOrder(root->left);
        cout<<root->data<<" ";
        inOrder(root->right);
    }

    void deleteDeepest(Node* root, Node* d_node)
    {
        queue<Node*> q;
        q.push(root);
        while(!q.empty())
        {
            Node* temp = q.front();
            q.pop();
            if(temp == d_node){
                temp = NULL;
                delete d_node;
                return;
            }
            if(temp->left)
            {
                if(temp->left == d_node){
                    temp->left = NULL;
                    delete d_node;
                    return;
                }
                else q.push(temp->left);
            }
            if(temp->right)
            {
                if(temp->right == d_node)
                {
                    temp->right = NULL;
                    delete d_node;
                    return;
                }
                else q.push(temp->right);
            } 
        }
    }
    Node* deleteNode(Node* root, int key)
    {
        if(!root) return NULL;
        if(!root->left && !root->right)
        {
            if(root->data == key)
            {
                delete root;
                return NULL;
            }
            else return root; 
        }
        queue<Node*> q;
        q.push(root);
        Node* key_node = NULL;
        Node* temp;
        while(!q.empty())
        {
            temp = q.front();
            q.pop();
            if(temp->data == key) key_node = temp;
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        if(key_node)
        {
            int x = temp->data;
            deleteDeepest(root,temp);
            key_node->data = x;
        }
        return root;
    }
    Node* getRoot() const{return root;}
};
int main()
{
    BT tree;
    tree.addNode(10);
    tree.addNode(20);
    tree.addNode(30);
    tree.addNode(40);
    tree.addNode(50);
    tree.addNode(60);
    tree.addNode(70);
    tree.addNode(80);
    tree.inOrder(tree.getRoot());
    tree.deleteNode(tree.getRoot(), 30);
    cout<<endl;
    tree.inOrder(tree.getRoot());
    return 0;
}
