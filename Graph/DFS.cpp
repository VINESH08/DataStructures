#include <iostream>
#include <vector>
using namespace std;
class DFS
{
private:
    void dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &ls)
    {
        vis[node] = 1;
        ls.push_back(node);
        for (auto it : adj[node])
        {
            if (!vis[it])
                dfs(it, adj, vis, ls);
        }
    }

public:
    vector<int> dfsTraversal(int num, vector<int> arclist[])
    {
        vector<int> v(num + 1, 0);
        int start = 1;
        vector<int> ls;
        dfs(start, arclist, v, ls);
        return ls;
    }
};
int main()
{
    DFS obj;
    int n, m, u, v;
    cout << "Enter the number of nodes:" << endl;
    cin >> n;
    cout << "Enter number of edges" << endl;
    cin >> m;
    cout << "Enter the nodes by their edges" << endl;
    vector<int> arclist[n + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        arclist[u].push_back(v);
        arclist[v].push_back(u);
    }
    vector<int> res = obj.dfsTraversal(n, arclist);
    for (auto it : res)
    {
        cout << it << " ";
    }
}