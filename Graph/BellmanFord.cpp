#include <iostream>
#include <iomanip>
#include <string>
using namespace std;
struct node
{
	int from;
	int to;
	int weight;
	node *next;
};
struct vnode
{
	string name;
	int d;
	int pi;
};
class graph
{
	int n, m;
	vnode vertex[10];
	node *elist;

public:
	void createGraph()
	{
		// string x = "4";
		// int y = stoi(x);
		// cout << y << endl;
		cout << "Enter number of vertices: ";
		cin >> n;

		for (int i = 1; i <= n; i++)
		{
			cout << "Enter name of the vertex - " << i << ": ";
			cin >> vertex[i].name;
		}
		cout << "Enter number of edges: ";
		cin >> m;
		elist = NULL;
		node *last = NULL;
		for (int j = 0; j < m; j++)
		{
			node *t = new node;
			cout << "Enter index of from vertex: ";
			cin >> t->from;
			cout << "Enter index of to vertex: ";
			cin >> t->to;
			cout << "Enter edge weight: ";
			cin >> t->weight;
			t->next = NULL;
			if (elist == NULL)
				elist = last = t;
			else
				last->next = t;
			last = t;
		}
	}
	void INITIALIZE_SINGLE_SOURCE(int s)
	{
		for (int i = 1; i <= n; i++)
		{
			vertex[i].d = 9999;
			vertex[i].pi = -1;
		}
		vertex[s].d = 0;
	}

	void RELAX(int u, int v, int w)
	{
		if (vertex[v].d > vertex[u].d + w)
		{
			vertex[v].d = vertex[u].d + w;
			vertex[v].pi = u;
		}
	}
	bool BellmanFord(int s)
	{
		INITIALIZE_SINGLE_SOURCE(s);

		for (int i = 1; i < n; i++)
		{
			node *t = elist;
			while (t != NULL)
			{
				RELAX(t->from, t->to, t->weight);
				t = t->next;
			}
		}
		node *t = elist;
		// Check for any negative cycle....
		while (t != NULL)
		{
			if (vertex[t->to].d > vertex[t->from].d + t->weight)
				return false;
			t = t->next;
		}
		return true;
	}
};
int main()
{
	graph obj;
	obj.createGraph();
	int st;
	cout << "Enter the start vertex" << endl;
	cin >> st;
	bool res = obj.BellmanFord(st);
	if (res)
		cout << "No negative cycle is present in the graph" << endl;
	else
		cout << "Negative cycle is present in the given graph" << endl;
}
