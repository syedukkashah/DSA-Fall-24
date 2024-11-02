#include <iostream>
#include <stack>
using namespace std;
class BST{
	struct Node{
		int data;
		Node* left;
		Node* right;

		Node(int val=0){
			data=val;
			left=right=nullptr;
		}
	};
	Node* root;
    void insertNode(Node* root, int val) //iterative approach
    {
        if(!root) root = new Node(val); //if tree is empty make new node the root
        else{
            Node* temp = root, *new_node = new Node(val);
            while(temp)
            {
                if(new_node->data == temp->data) return; //no duplicates allowed
                else if(new_node->data < temp->data && !temp->left) //if at left most node and new node value is smaller
                {
                    temp->left = new_node; 
                    break;
                }
                else if(new_node->data < temp->data) temp = temp->left; //traverse to left node if not left most 
                else if(new_node->data > temp->data && !temp->right)
                {
                    temp->right = new_node;
                    break;
                }
                else temp = temp->right;
            }
        }
    }
    Node* insert(Node* root, int val){ //recursive approach
        if(!root) return new Node(val);
        if(val == root->data) return root; //check for duplicates
        //otherwise recur down the tree
        if(val < root->data) root->left = insert(root->left, val); 
        else root->right= insert(root->right, val);
        return root;
        //return the unchanged root ptr;
    }

    //DFS includes Pre-order, In-order, Post-order
    void printPreorder(Node* r) //NLR
    {
        if(!r) return;
        cout<<r->data<<endl;
        printPreorder(r->left);
        printPreorder(r->right);
    }
    void printInOrder(Node* r) //LNR
    {
        printInOrder(r->left);
        cout<<r->data<<endl;
        printInOrder(r->right);
    }
    void printPostOrder(Node* r) //LRN
    {
        printPostOrder(r->left);
        printPostOrder(r->right);
        cout<<r->data<<endl;
    }




};
