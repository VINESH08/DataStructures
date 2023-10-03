#include <iostream>
#include <vector>
using namespace std;
void SieveOfErathosthenes(int n)
{
    vector<bool> prime(n + 1, true);
    prime[0] = prime[1] = false; // 0 and 1 are not prime
    for (int p = 2; p * p <= n; p++)
    {
        if (prime[p] == true)
        { // it is a prime number
            for (int i = p * p; i <= n; i += p)
            {
                prime[i] = false;
            }
        }
    }

    for (int i = 2; i <= n; i++)
    {
        if (prime[i])
        {
            cout << i << " ";
        }
    }
}
int main()
{
    int n;
    cout << "Enter the limit: ";
    cin >> n;
    cout << "Prime numbers up to " << n << " are: ";
    SieveOfErathosthenes(n);
    cout << endl;
    cout << min(5, 4);
    return 0;
}