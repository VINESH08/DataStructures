#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <string>
using namespace std;
int **s;
class MCM
{
public:
    int **m;

    MCM(int mrow, int mcol, int srow, int scol)
    {
        m = new int *[mrow];
        for (int i = 0; i < mrow; i++)
            m[i] = new int[mcol];
        s = new int *[srow];
        for (int i = 0; i < srow; i++)
            s[i] = new int[scol];
    }
    void matrix_chain_order(int p[], int n)
    {
        for (int i = 0; i < n; i++)
            m[i][i] = 0;
        for (int l = 2; l <= n; l++)
        {
            for (int i = 0; i < n - l + 1; i++)
            {
                int j = i + l - 1;
                m[i][j] = INT_MAX;
                for (int k = i; k <= j - 1; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + (p[i - 1] * p[k] * p[j]);
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }
    void print(int i, int j)
    {
        if (i == j)
            cout << "A" << i + 1;
        else
        {
            cout << "(";
            print(i, s[i][j]);
            print(s[i][j] + 1, j);
            cout << ")";
        }
    }
};
int main()
{
    int n, m;
    cout << "Enter the number of matrices" << endl;
    cin >> n;
    cout << "Enter the array size" << endl;
    cin >> m;
    int arr[m];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < m; i++)
    {
        cin >> arr[m];
    }
    MCM obj(n, n, n, n);
    obj.matrix_chain_order(arr, n);
    obj.print(0, n - 1);
}