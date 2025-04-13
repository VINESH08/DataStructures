#include <iostream>
#include <vector>
using namespace std;
class DisJointSet
{
    vector<int> rank, parent;

public:
    DisJointSet(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1);
        for (int i = 0; i < n; i++)
        {
            parent[i] = i;
        }
    }
    int findParent(int u)
    { // finding the ultimate Parent
        if (u == parent[u])
            return u;
        return parent[u] = findParent(parent[u]); // PathCompression..
    }
    void UnionByRank(int u, int v)
    {
        int pu = findParent(u);
        int pv = findParent(v);
        int rankpu = rank[pu];
        int rankpv = rank[pv];
        if (pu == pv)
            return;
        if (rankpu < rankpv)
        {
            parent[pu] = pv;
        }
        else if (rankpv < rankpu)
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pu] = pv;
            rank[pv]++;
        }
    }
};
int main()
{
    DisJointSet dsu(7);
    dsu.UnionByRank(1, 2);
    dsu.UnionByRank(2, 3);
    dsu.UnionByRank(4, 5);
    dsu.UnionByRank(6, 7);
    dsu.UnionByRank(5, 6);
    if (dsu.findParent(3) == dsu.findParent(7))
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not same" << endl;
    cout << "----------" << endl;
    dsu.UnionByRank(3, 7);

    if (dsu.findParent(3) == dsu.findParent(7))
    {
        cout << "Same" << endl;
    }
    else
        cout << "Not same" << endl;
}