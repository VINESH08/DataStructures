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
    void input(int vsize)
    {
        int inarr[vsize];
        int outarr[vsize];
        int incount = 0;
        int outcount = 0;
        for (int i = 0; i < vsize; i++)
        {
            for (int j = 0; j < vsize; j++)
            {
                cout << "Enter element:" << i + 1 << "," << j + 1 << "Element" << endl;
                cin >> w[i][j];
            }
        }
        // indegree->column, outdegree->row now for verte:
        // indegree
        for (int i = 0; i < vsize; i++)
        {
            for (int j = 0; j < vsize; j++)
            {
                if (w[j][i] != 0 && w[j][i] != 999)
                {
                    incount++;
                }
            }
            inarr[i] = incount;
            incount = 0;
        }
        // indegree
        for (int i = 0; i < vsize; i++)
        {
            for (int j = 0; j < vsize; j++)
            {
                if (w[i][j] != 0 && w[i][j] != 999)
                {
                    outcount++;
                }
            }
            outarr[i] = outcount;
            outcount = 0;
        }
        cout << "indegree" << endl;
        for (int i = 0; i < vsize; i++)
        {
            cout << inarr[i] << ' ';
        }
        for (int i = 0; i < vsize; i++)
        {
            cout << outarr[i] << ' ';
        }
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
    int vsize;
    cout << "Enter the number of edges" << endl;
    cin >> size;
    cout << "Enter the number of vertices:" << endl;
    cin >> vsize;
    FloydWarshall obj(vsize);
    obj.input(vsize);
    obj.intialize(vsize);
    obj.floydwarshall(vsize);
    obj.output(vsize);
}
