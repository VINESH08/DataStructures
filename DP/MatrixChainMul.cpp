#include <iostream>
#include <climits>
using namespace std;

class MCM
{
private:
    int **m;
    int **s;
    int mrow, mcol, srow, scol;

public:
    MCM(int size)
    {
        mrow = mcol = srow = scol = size;
        m = new int *[mrow];
        for (int i = 0; i < mrow; i++)
            m[i] = new int[mcol];
        s = new int *[srow];
        for (int i = 0; i < srow; i++)
            s[i] = new int[scol];
    }

    ~MCM()
    {
        for (int i = 0; i < mrow; i++)
            delete[] m[i];
        delete[] m;

        for (int i = 0; i < srow; i++)
            delete[] s[i];
        delete[] s;
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
                for (int k = i; k < j; k++)
                {
                    int q = m[i][k] + m[k + 1][j] + p[i] * p[k + 1] * p[j + 1];
                    if (q < m[i][j])
                    {
                        m[i][j] = q;
                        s[i][j] = k;
                    }
                }
            }
        }
    }

    void print_optimal_parens(int i, int j)
    {
        if (i == j)
            cout << "A" << i + 1;
        else
        {
            cout << "(";
            print_optimal_parens(i, s[i][j]);
            print_optimal_parens(s[i][j] + 1, j);
            cout << ")";
        }
    }
};

int main()
{
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    int arrSize = n + 1;
    int arr[arrSize];
    cout << "Enter " << arrSize << " dimensions for the matrices:" << endl;
    for (int i = 0; i < arrSize; i++)
    {
        cin >> arr[i];
    }

    MCM obj(n);
    obj.matrix_chain_order(arr, n);
    cout << "Optimal parenthesization is: ";
    obj.print_optimal_parens(0, n - 1);
    cout << endl;

    return 0;
}
