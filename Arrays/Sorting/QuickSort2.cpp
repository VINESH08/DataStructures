#include <iostream>
using namespace std;
class QuickSort
{
private:
    int size;
    int *arr;

public:
    QuickSort(int n)
    {
        size = n;
        arr = new int[size];
    }
    void Exchange(int &a, int &b)
    {
        int temp = a;
        a = b;
        b = temp;
    }
    void quciksort(int i, int j)
    {
        if (i < j)
        {
            int k = Partition(i, j);
            quciksort(i, k - 1);
            quciksort(k + 1, j);
        }
    }
    int Partition(int p, int r)
    {
        int pivot = arr[r];
        int i = p - 1;

        for (int j = p; j <= r - 1;)
        {
            if (arr[j] <= pivot)
            {
                i++;
                Exchange(arr[i], arr[j]);
                j++;
            }
            else
                j++;
        }
        Exchange(arr[r], arr[i + 1]);
        return i + 1;
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << arr[i] << " ";
        }
    }
    void input()
    {
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
};
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    QuickSort q(n);
    q.input();
    q.quciksort(0, n - 1);
    q.print();
}