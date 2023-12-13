#include <iostream>
using namespace std;
int Series(double n)
{
    if (n == 0)
        return 0.0;
    else
        return ((1 / n) + Series(n - 1.0));
}
int main()
{
    double n;
    cin >> n;
    cout << Series(n);
}