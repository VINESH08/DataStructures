#include <iostream>
#include <climits>
using namespace std;
class RodBU
{
private:
    int *r;
    int *s;
    int rs;

public:
    RodBU(int rsize, int ssize)
    {
        rs = rsize;
        r = new int[rsize];
        s = new int[ssize];
    }
    int Rodcutting(int p[], int n, int &cut)
    {
        r[0] = 0;
        s[0] = 0;
        for (int j = 1; j < n; j++)
        {
            int q = INT_MIN;
            for (int i = 1; i <= j; i++)
            {
                if (q < p[i] + r[j - i])
                {
                    q = p[i] + r[j - i];
                    s[j] = i; // where the cut has to be made..:)
                }
            }
            r[j] = q;
        }
        cut = s[rs - 1];
        return r[rs - 1];
    }
};
int main()
{
    int rodsize;
    int cut = 0;
    cout << "Enter the size of the rod" << endl;
    cin >> rodsize;
    int parr[rodsize + 1];
    parr[0] = 0;
    cout << "Enter the cost matrix:" << endl;
    for (int i = 1; i <= rodsize; i++)
    {
        cout << "Cost for length " << i << ":";
        cin >> parr[i];
    }
    RodBU obj(rodsize + 1, rodsize + 1);
    int k = obj.Rodcutting(parr, rodsize + 1, cut);
    cout << "Maximum revenue obtained:" << k << endl;
    cout << "Cut:" << cut << endl;
}