#include "iostream"
#include "vector"
using namespace std;
void add_edge(vector<vector<int>>& adj, int i, int v)
{
    //directed graph
    adj[i].push_back(v);
    adj[v].push_back(i);
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
    vector<vector<int>> mat(4); //size 4
    add_edge(mat, 1, 0); // 1->0,0->1
    add_edge(mat, 2, 0); // 2->0, 0->2
    add_edge(mat, 3, 1); //3->1, 1->3
    display(mat);
    return 0;
}
