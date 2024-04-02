#include <iostream>
#include <climits>
using namespace std;
class MCMTD
{
private:
    int **m;
    int **s;
    int mrow, mcol, srow, scol;

public:
    MCMTD(int size)
    {
        mrow = mcol = srow = scol = size;
        m = new int *[mrow];
        for (int i = 0; i < mrow; i++)
            m[i] = new int[mcol];
        s = new int *[srow];
        for (int i = 0; i < srow; i++)
            s[i] = new int[scol];
        for (int i = 0; i < mrow; i++)
        {
            for (int j = 0; j < mcol; j++)
            {
                m[i][j] = -1;
            }
        }
    }
    int Mat_TD(int p[], int i, int j)
    {
        if (m[i][j] != -1)
            return m[i][j];
        if (i == j)
        {
            m[i][j] = 0;
            return m[i][j];
        }
        int t = INT_MAX;

        for (int k = i; k < j; k++)
        {
            int q = Mat_TD(p, i, k) + Mat_TD(p, k + 1, j) + (p[i] * p[k + 1] * p[j + 1]);
            if (q < t)
            {
                t = q;
                s[i][j] = k;
            }
        }
        m[i][j] = t;

        return t;
    }
    void printsol(int i, int j)
    {
        if (i == j)
            cout << "A" << i + 1 << " ";
        else
        {
            cout << "(";
            printsol(i, s[i][j]);
            printsol(s[i][j] + 1, j);
            cout << ")";
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of matrices" << endl;
    cin >> n;
    int arrsize = n + 1;
    int arr[arrsize];
    cout << "Enter the dimension array" << endl;
    for (int i = 0; i < arrsize; i++)
    {
        cin >> arr[i];
    }
    MCMTD obj(n);
    obj.Mat_TD(arr, 0, n - 1);
    obj.printsol(0, n - 1);
}