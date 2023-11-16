#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class BFS
{
public:
    vector<int> BFStraversal(int n, vector<int> adj[])
    {
        vector<int> vis(n + 1, 0);
        int start = 6;
        vis[start] = 1;
        queue<int> q;
        q.push(start);
        vector<int> res;
        while (!q.empty())
        {
            int p = q.front();
            q.pop();
            res.push_back(p);
            for (auto it : adj[p])
            {
                if (!vis[it])
                {
                    vis[it] = 1;
                    q.push(it);
                }
            }
        }
        return res;
    }
};
int main()
{
    BFS g;
    int n, m;
    int u, v;
    cout << "Enter the number of nodes" << endl;
    cin >> n;
    cout << "Enter the number of edges" << endl;
    cin >> m;
    vector<int> adj[n + 1];
    cout << "Enter the edges" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    vector<int> result = g.BFStraversal(n, adj);
    for (auto it : result)
    {
        cout << it << " ";
    }
}