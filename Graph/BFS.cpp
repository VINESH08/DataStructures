#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class BFS
{
public:
    vector<int> BFStraversal(int n, vector<int> adj[], int start)
    {
        vector<int> vis(n + 1, 0);
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
    int u, v, start;
    cout << "Enter the number of nodes: ";
    cin >> n;
    cout << "Enter the number of edges: ";
    cin >> m;
    vector<int> adj[n + 1];
    cout << "Enter the edges: " << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> u >> v;
        if (u < 1 || u > n || v < 1 || v > n)
        {
            cout << "Invalid edge!" << endl;
            return 1;
        }
        adj[u].push_back(v);
        adj[v].push_back(u); // Remove this line if directed graph is needed.
    }
    cout << "Enter the starting node: ";
    cin >> start;
    vector<int> result = g.BFStraversal(n, adj, start);
    for (auto it : result)
    {
        cout << it << " ";
    }
    cout << endl;
}
