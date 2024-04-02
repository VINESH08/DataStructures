#include <iostream>
using namespace std;
#define MAXN 10   // Adjust based on maximum subset size you expect
#define MAXM 1024 // Adjust based on maximum number of solutions you expect

struct Subset
{
    int X[MAXN];
    int n;
    Subset(int size = 0)
    { // Default constructor with optional size argument
        n = size;
        for (int i = 0; i < n; i++)
            X[i] = 0;
    }
};

void PrintSubset(Subset ssAll[], int solutionSize, int set[], int n)
{
    cout << "\n\tNumber of Solutions: " << solutionSize;
    cout << "\n\tSolutions: ";
    for (int i = 0; i < solutionSize; i++)
    {
        cout << "\n\t\t{ ";
        for (int j = 0; j < n; j++)
        {
            if (ssAll[i].X[j])
                cout << set[j] << "\t";
        }
        cout << "}";
    }
}

void SubSetSum(int i, int n, int set[], int balanceSum, Subset ss, Subset ssAll[], int &solutionSize)
{
    if (balanceSum == 0)
    {
        // Solution Found, Record the Solution
        ssAll[solutionSize++] = ss;
        return;
    }
    if (balanceSum < 0 || i == n)
    {
        // No Solution or No more elements to include
        return;
    }
    // Include current item
    ss.X[i] = 1;
    SubSetSum(i + 1, n, set, balanceSum - set[i], ss, ssAll, solutionSize);

    // Exclude current item
    ss.X[i] = 0;
    SubSetSum(i + 1, n, set, balanceSum, ss, ssAll, solutionSize);
}

int main()
{
    int sum;
    int n;
    Subset ss;
    Subset ssAll[MAXM];
    int solutionSize;

    // Test case 1
    int set1[] = {10, 7, 5, 18, 12, 20, 15};
    sum = 35;
    n = sizeof(set1) / sizeof(set1[0]);
    ss = Subset(n);
    solutionSize = 0;
    SubSetSum(0, n, set1, sum, ss, ssAll, solutionSize);
    cout << "\n\nTest Case 1: ";
    PrintSubset(ssAll, solutionSize, set1, n);

    // Additional test cases follow the same pattern...

    return 0;
}
