#include <iostream>
#include <limits.h>
#include <fstream>
#include <stdlib.h>
#include <time.h>
using namespace std;
class CountSort
{
private:
    int *A;
    int *B;
    int *C;
    int size;
    int count;
    int k = INT_MIN;

public:
    CountSort(int n)
    {
        count = 0;
        size = n;
        A = new int[size];
        B = new int[size];
    }
    void input()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> A[i];
            if (A[i] > k)
                k = A[i];
        }
    }
    void countingsort()
    {
        C = new int[k + 1];
        for (int i = 0; i <= k; i++)
        {
            C[i] = 0;
            count++;
        }
        for (int j = 0; j < size; j++)
        {
            C[A[j]] = C[A[j]] + 1;
            count++;
        }
        for (int i = 1; i < k + 1; i++)
        {
            count++;
            C[i] = C[i] + C[i - 1];
        }
        for (int j = size - 1; j >= 0; j--)
        {
            count++;
            B[C[A[j]] - 1] = A[j];
            C[A[j]] = C[A[j]] - 1;
        }
    }
    void output()
    {
        for (int i = 0; i < size; i++)
            cout << B[i] << " ";
    }
};
int main()
{
    int n;
    cout << "Enter the size " << endl;
    cin >> n;
    CountSort ob(n);
    cout << "Enter elements" << endl;
    ob.input();
    ob.countingsort();
    ob.output();
}
