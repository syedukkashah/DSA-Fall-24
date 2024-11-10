#include "iostream"
#include "queue"
#include "string"
#include "cstdlib"
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
    void serializeHelper(Node* root, string& output)
    {
        if(!root){
            output+="# ";
            return;
        }
        output+=to_string(root->data) + " ";
        serializeHelper(root->left, output);
        serializeHelper(root->right, output);
    }
    string serialize(Node* root){
        string output = " ";
        serializeHelper(root,output);
        return output;
    }

    Node* deserializeHelper(string& output, int& index){
        if(index>=output.size()) return NULL;
        while(index < output.size() && output[index]!=' ') index++;
        if(output[index] == '#' || index>=output.size())
        {
            index+=2;
            return NULL;
        } 
        int numStart = index;
        while(index < output.size() && output[index]!=' ') index++;
        string nodeDatastr = output.substr(numStart, index - numStart);
        if(nodeDatastr.empty()) return NULL;
        int nodeData = 0;
        try{
            nodeData = stoi(nodeDatastr);
        }
        catch(const invalid_argument& e){ return NULL;}
        index++;

        Node* n = new Node(nodeData);
        n->left = deserializeHelper(output, index);
        n->right = deserializeHelper(output, index);
        return n;
    }
    void deserialize(string& data){;
        int idx = 0;
        root = deserializeHelper(data,idx);
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
    string transmission = tree.serialize(tree.getRoot());
    cout<<transmission<<endl;

    BT newTree;
    newTree.deserialize(transmission);
    string reserialized = newTree.serialize(tree.getRoot());
    cout<<reserialized<<endl;
    return 0;
}
