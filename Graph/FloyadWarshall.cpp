#include <iostream>
#include <climits>
using namespace std;
class FloydWarshall
{
private:
    int **pi;
    int **d;
    int **w;

public:
    FloydWarshall(int size)
    {
        pi = new int *[size];
        for (int i = 0; i < size; i++)
            pi[i] = new int[size];
        d = new int *[size];
        for (int i = 0; i < size; i++)
            d[i] = new int[size];
        w = new int *[size];
        for (int i = 0; i < size; i++)
            w[i] = new int[size];
    }
    void intialize(int wrows)
    {
        int n = wrows;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                d[i][j] = w[i][j];
                if (i == j || w[i][j] == 999)
                    pi[i][j] = -1;
                else
                    pi[i][j] = i + 1;
            }
        }
    }
    void floydwarshall(int drows)
    {
        int n = drows;
        for (int k = 0; k < n; k++)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (pi[i][k] != -1 && pi[k][j] != -1 && d[i][j] > (d[i][k] + d[k][j]))
                    {
                        d[i][j] = d[i][k] + d[k][j];
                        pi[i][j] = pi[k][j];
                    }
                }
            }
        }
    }
    void input(int size)
    {

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << "Enter element:" << i + 1 << "," << j + 1 << "Element" << endl;
                cin >> w[i][j];
            }
        }
        // indegree->column, outdegree->row now for vertex 5:
        int incount = 0;
        int outcount = 0;
        for (int i = 0; i < 5; i++)
        {
            // indegree
            if (w[i][4] != 0 && w[i][4] != 999)
                incount++;
        }
        for (int i = 0; i < 5; i++)
        {
            if (w[4][i] != 0 && w[4][i] != 999)
                outcount++;
        }
        cout << "Indegree:" << incount << endl;
        cout << "Outdegree:" << outcount << endl;
    }
    void output(int size)
    {
        cout << "MATRIX D" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << d[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        cout << "MATRIX pi" << endl;
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                cout << pi[i][j] << " ";
            }
            cout << endl;
        }
    }
};
int main()
{
    int size;
    cout << "Enter the number of edges" << endl;
    cin >> size;
    FloydWarshall obj(size);
    obj.input(size);
    obj.intialize(size);
    obj.floydwarshall(size);
    obj.output(size);
}
