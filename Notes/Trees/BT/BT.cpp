#include "iostream"
#include "vector"
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

static int numNodes = 0, total = 0; //used to calculate number of nodes in size function as well as total sum

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

    static int size(Node* r)
    {
        if(!r) return numNodes;
        else{
            size(r->left);
            numNodes++; //we can calculate size by using any traversal method, we simply replace the cout with an int increment
            size(r->right);
        }
        return numNodes;
    }
    int countNodes(Node* r){
        if(!r) return 0;
        else return 1+countNodes(r->left)+countNodes(r->right); //alternate method of counting nodes (traversing root's left & right ST & adding 1 to include root)
    }
    void countLeaves(Node* r, int& leaves)
    {
        if(!r) return;
        if(!r->left && !r->right) leaves++; //if a node has no children we increment cnt
        //we traverse left and right sub-trees
        countLeaves(r->left, leaves); 
        countLeaves(r->right, leaves);
    }
    void countInternalNodes(Node* r, int& internal)
    {
        if(!r) return;
        if(r->left || r->right) internal++; //if a node has a child we increment count 
        //we traverse left and right sub-trees
        countInternalNodes(r->left, internal);
        countInternalNodes(r->right, internal);
    }
    static int sum(Node* r)
    {
        if(!r) return total;
        else{
            sum(r->left);
            total+=r->data; //we can calculate sum by using any traversal method
            sum(r->right);
        }
        return total;
    }
    int height(Node* r){
        if(!r) return 0;
        int a = height(r->left); //height of left sub-tree
        int b = height(r->right); //height of right sub-tree
        return 1 + max(a,b); //return the larger height + 1 to accommodate for root 
    }
    int minDepth(Node* r) {
        if(!r) return 0;
        int left = minDepth(r->left);
        int right = minDepth(r->right);
        if(left==0||right==0) return 1 + max(left, right); //if a subtree doesn't exist we will return the largest and the only subtree present
        return 1 + min(left, right); //otherwise we return the minimum depth subtree
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
    void levelOrder() //we insert Nodes in level order so here the implementation is the same as insertion 
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

    //https://www.geeksforgeeks.org/largest-value-level-binary-tree/
    void largestElementPerLevel(vector<int>& largest, Node* r, int depth)
    {
        if(!r) return;
        else{
            if(depth == largest.size()) largest.push_back(r->data); // if current depth equals size of array it means a node hasn't been encountered at this level so we add current node's val to array
            else largest[depth] = max(largest[depth], r->data); //if a node has already been encountered at this level, store max element
            largestElementPerLevel(largest, r->left, depth+1); //traverse left subtree and increase depth
            largestElementPerLevel(largest, r->right, depth+1); //traverse right subtree and increase depth
        }
    }
    /*max path sum strategy:
       for each node compute
       (1)node val
       (2)max path through left child + node val
       (3)max path through right child + node val
       (4)max path through left & right child + node val
    */

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
   //code that merges two trees, if both nodes exist, values of those nodes are added
   Node* mergeTrees(Node* root1, Node* root2) {
        if(!root1) return root2;
        else if (!root2) return root1;
        else{
            root2->left = mergeTrees(root1->left, root2->left);
            root2->data += root1->data;
            root2->right = mergeTrees(root1->right, root2->right);
        }
        return root2;
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
    tree.addNode(51);
/*
    BT structure after inserting 1,2,3,4,5,10,50,51
               1
            /    \
           2      3
         /   \   /  \ 
        4     5 10   50  
      /
    51 
*/
    tree.inOrder(tree.getRoot());
    cout<<endl;
    tree.postOrder(tree.getRoot());
    cout<<endl;
    tree.preOrder(tree.getRoot());
    cout<<endl;
    tree.levelOrder();
    cout<<endl;
    cout<<tree.size(tree.getRoot())<<endl;
    cout<<tree.countNodes(tree.getRoot())<<endl;
    int numLeaves = 0;
    tree.countLeaves(tree.getRoot(), numLeaves);
    cout<<numLeaves<<endl;
    int numInternalNodes = 0;
    tree.countInternalNodes(tree.getRoot(), numInternalNodes);
    cout<<numInternalNodes<<endl;
    cout<<tree.sum(tree.getRoot())<<endl;
    cout<<tree.height(tree.getRoot())<<endl;
    cout<<tree.minDepth(tree.getRoot())<<endl;
    vector<int> max;
    tree.largestElementPerLevel(max, tree.getRoot(), 0);
    for (int n: max) cout<< n <<" ";
    cout<<endl;
    cout<<tree.maxPathSum(tree.getRoot());
    return 0;
}
