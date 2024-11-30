#include <iostream>
#include <queue>
#include <vector>
using namespace std;
class Node {
public:
    vector<int> keys; 
    vector<Node*> children;
    Node(vector<int> keys) : keys(keys) {}
};
void levelOrderTraversal(Node* root) {
    if (!root) return;
    queue<Node*> q;  
    q.push(root);
    while (!q.empty()) {
        int levelSize = q.size();
        for (int i = 0; i < levelSize; i++) {
            Node* current = q.front();
            q.pop();
            for (int key : current->keys) {
                cout << key << " ";
            }
            for (Node* child : current->children) {
                if (child)q.push(child);
            }
        }
        cout << endl;
    }
}
int main() {
    Node* root = new Node({30});  
    root->children.push_back(new Node({10, 20}));  
    root->children.push_back(new Node({40, 50}));  
    root->children[0]->children.push_back(new Node({5}));
    root->children[0]->children.push_back(new Node({15}));
    root->children[0]->children.push_back(new Node({25}));
    root->children[1]->children.push_back(new Node({35}));
    root->children[1]->children.push_back(new Node({45}));
    root->children[1]->children.push_back(new Node({55}));
    cout << "Level-Order Traversal:" << endl;
    levelOrderTraversal(root);
    return 0;
}
