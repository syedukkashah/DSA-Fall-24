#include "iostream"
#include "vector"
#include "queue"
using namespace std;
void add_edge(vector<vector<int>>& adj, int i, int v)
{
    //directed graph
    adj[i].push_back(v);
    adj[v].push_back(i);
}
vector<int> BFS(vector<vector<int>>& adj, int src)
{
    queue<int> q;
    q.push(src); //enqueue src node
    vector<bool> visited(adj.size(), false); //init visited to false idx
    visited[src] = true; //mark src node as visited
    vector<int>ans;
    int node;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        ans.push_back(node);
        for(int j=0; j<adj[node].size(); j++)
        {
            if(!visited[adj[node][j]]) 
            {
                visited[adj[node][j]] = true;
                q.push(adj[node][j]);
            }
        }
    }
    return ans;
}
void display(vector<vector<int>>& adj)
{
    for(int i=0; i<adj.size(); i++)
    {
        cout<<i<<" : ";
        for(int adjacent: adj[i])
        {
            cout<<adjacent<<" ";
        }
        cout<<endl;
    }
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
    display(adj_list);
    vector<int>ans = BFS(adj_list, 5);
    for(int i=0; i<ans.size(); i++) cout<<ans[i]<<" ";
    return 0;
}
