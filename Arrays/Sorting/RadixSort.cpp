#include <iostream>
#include <limits.h>
#include <algorithm> // For std::max
using namespace std;

class RadixSort
{
private:
    int *A;

    int size;

public:
    RadixSort(int n)
    {
        size = n;
        A = new int[size];
    }
    void input()
    {
        cout << "Enter elements: " << endl;
        for (int i = 0; i < size; i++)
        {
            cin >> A[i];
        }
    }

    // A utility function to get the maximum value in A[]
    int getMax()
    {
        int mx = A[0];
        for (int i = 1; i < size; i++)
            if (A[i] > mx)
                mx = A[i];
        return mx;
    }

    // A function to do counting sort of A[] according to the digit represented by exp.
    void countSort(int exp)
    {
        int output[size]; // output array
        int i, count[10] = {0};

        // Store count of occurrences in count[]
        for (i = 0; i < size; i++)
            count[(A[i] / exp) % 10]++;

        // Change count[i] so that count[i] now contains actual position of this digit in output[]
        for (i = 1; i < 10; i++)
            count[i] += count[i - 1];

        // Build the output array
        for (i = size - 1; i >= 0; i--)
        {
            output[count[(A[i] / exp) % 10] - 1] = A[i];
            count[(A[i] / exp) % 10]--;
        }

        // Copy the output array to A[], so that A[] now contains sorted numbers according to current digit
        for (i = 0; i < size; i++)
            A[i] = output[i];
    }

    // The main function to that sorts A[] of size n using Radix Sort
    void radixsort()
    {
        // Find the maximum number to know number of digits
        int m = getMax();

        // Do counting sort for every digit. Note that instead of passing digit number, exp is passed. exp is 10^i where i is current digit number
        for (int exp = 1; m / exp > 0; exp *= 10)
            countSort(exp);
    }

    void output()
    {
        for (int i = 0; i < size; i++)
            cout << A[i] << " ";
        cout << endl;
    }
};

int main()
{
    int n;
    cout << "Enter the size: ";
    cin >> n;
    RadixSort ob(n);
    ob.input();
    ob.radixsort();
    cout << "Sorted elements: " << endl;
    ob.output();
    return 0;
}
