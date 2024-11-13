#include "iostream"
using namespace std;
class Node{
    public:
    int data;
    Node *right, *left, *next;
    Node(int d):data(d), right(NULL), left(NULL), next(NULL){}
    friend class BT;
    friend class queue;
};
class queue{  //rear = tail, front = head (FIFO)
   Node *front, *rear; 
   public:
   queue():front(NULL), rear(NULL){}
   void enqueue(Node* n)
   {
        if(!front)
        {
            front = rear = n;
            return;
        }
        else{
            rear->next = n;
            rear = n;
        }
   }
   void dequeue()
   {
        if(isEmpty()) return;
        front = front->next; // Move the front pointer to the next node
        // We do not delete temp here
        if(!front) rear = NULL; // If the queue becomes empty, set rear to NULL
   }

   bool isEmpty() const {return front == NULL;}
   Node* getFront() const{return front;}
   void print(){
    Node* curr = front;
    while(curr){
        cout<<front->data<<" ";
        curr = curr->next;
    }
   }
};
class BT{
    Node* root;
    public:
    BT():root(NULL){}
    void addNode(int d){ 
    queue q; //since we are not deleting nodes when dequeuing, we will declare a new queue every time a function needs to use it
    Node* n = new Node(d);
        if(!root) root = n;
        else{
                q.enqueue(root); 
                while(!q.isEmpty())
                {
                    Node* curr = q.getFront(); //save front of queue before dequeueing
                    q.dequeue();
                    if(!curr->left){ //if there is no left child, we insert node
                        curr->left = n;
                        return;
                    }
                    else q.enqueue(curr->left); //if left child existed we enqueue it
                    if(!curr->right) //if there is no right child, we insert node
                    {
                        curr->right = n;
                        return;
                    }
                    else q.enqueue(curr->right); //if right child existed then we enqueue it
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
        queue q;
        q.enqueue(root);
        while(!q.isEmpty())
        {
            Node* n = q.getFront();
            cout<<q.getFront()->data<<" ";
            q.dequeue();
            if(n->left) q.enqueue(n->left);
            if(n->right)q.enqueue(n->right);
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
 /*
    BT structure after inserting 1,2,3,4,5,10,50

           1
        /    \
      2       3
    /   \    /  \ 
   4     5  10   50  

*/
    tree.inOrder(tree.getRoot());
    cout<<endl;
    tree.postOrder(tree.getRoot());
    cout<<endl;
    tree.preOrder(tree.getRoot());
    cout<<endl;
    tree.levelOrder();
    return 0;

}