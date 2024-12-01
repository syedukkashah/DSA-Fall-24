#include "iostream"
#include "queue"
#include "stack"
using namespace std;
class Node{
    public:
    int val;
    Node *right, *left;
    Node(int d):val(d), right(NULL), left(NULL){}
};
    
	Node* firstMistake, *secondMistake, *pre;
	void inorder(Node* root) {
		if(!root) return;
		inorder(root->left);
		if(!firstMistake && root->val < pre->val) firstMistake = pre;
		if(firstMistake && root->val < pre->val) secondMistake = root;
		pre = root;
		inorder(root->right);
	}
	void recoverTree(Node* root) {
		pre = new Node(INT16_MIN);
		inorder(root);
		swap(firstMistake->val, secondMistake->val);
	}

    void levelOrder(Node* r)
    {
        queue<Node*> q;
        q.push(r);
        while(!q.empty())
        {
            Node* curr = q.front();
            cout<<q.front()->val<<" ";
            q.pop();
            if(curr->left) q.push(curr->left);
            if(curr->right) q.push(curr->right);
        }
    }

int main()
{
    Node* root = new Node(10);
    root->left = new Node(4);
    root->right= new Node(15);
    root->left->left= new Node(2);
    root->left->right= new Node(12);
    root->left->right->left= new Node(6);
    root->left->right->right= new Node(9);
    root->right->right = new Node(18);
    root->right->left= new Node(7);
    recoverTree(root);
    levelOrder(root);
}