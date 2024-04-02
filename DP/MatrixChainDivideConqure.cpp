#include <iostream>
#include <climits>
using namespace std;
class MCMDC
{
public:
    int Mat_rec(int p[], int i, int j)
    {
        if (i == j)
            return 0;
        int t = INT_MAX;
        for (int k = i; k < j; k++)
        {
            int q = Mat_rec(p, i, k) + Mat_rec(p, k + 1, j) + (p[i] * p[k + 1] * p[j + 1]);
            if (q < t)
                t = q;
        }
        return t;
    }
};
int main()
{

    int p[] = {10, 100, 9, 50};
    int n = sizeof(p) / sizeof(p[0]) - 1;

    MCMDC mcmdc;

    int result = mcmdc.Mat_rec(p, 0, n - 1);

    cout << "Minimum number of multiplications is " << result << endl;

    return 0;
}
