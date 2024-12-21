#include "iostream"
#include "vector"
using namespace std;
void add_edge(vector<vector<int>>& mat, int i, int j, int weight)
{
    //singular idx init if graphs is directed, both if undirected. init to 1 if unweighted
    mat[i][j] = weight;
}
void display(vector<vector<int>>& mat)
{
    for(int i=0; i<mat.size(); i++)
    {
        for(int j=0; j<mat[i].size(); j++)
        {
            cout<<mat[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    vector<vector<int>> mat(4,vector<int>(4, 0)); //size 4, all idx init to 0
    add_edge(mat, 1, 0, 2); // 1->0, 
    add_edge(mat, 2, 0, 4); // 2->0
    add_edge(mat, 3, 1, 2); //3->1
    display(mat);
    return 0;
}