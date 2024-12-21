#include "iostream"
#include "vector"
using namespace std;
void DFSRec(vector<vector<int>> &adj, vector<bool> &visited, int s) {
    visited[s] = true;
    cout << s << " ";
    for (int i : adj[s])
        if (visited[i] == false)
            DFSRec(adj, visited, i);
}
void DFS(vector<vector<int>> &adj, int s) {
    vector<bool> visited(adj.size(), false);
    DFSRec(adj, visited, s);
}
void add_edge(vector<vector<int>>& adj, int i, int v)
{
    //directed graph
    adj[i].push_back(v);
    adj[v].push_back(i);
}
int main()
{
    vector<vector<int>> adj_list(9);
    add_edge(adj_list, 0, 1); 
    add_edge(adj_list, 0, 2); 
    add_edge(adj_list, 1, 5); 
    add_edge(adj_list, 1, 7); 
    add_edge(adj_list, 2, 3); 
    add_edge(adj_list, 2, 4); 
    add_edge(adj_list, 5, 6); 
    add_edge(adj_list, 6, 8); 
    add_edge(adj_list, 7, 8);
    DFS(adj_list, 5);
    return 0;
}
