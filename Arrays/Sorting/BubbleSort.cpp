#include <iostream>
using namespace std;
void Exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void Bubblesort(int list[], int n)
{
    int current = 0;
    bool sorted = false;
    while (current < n - 1 && sorted == false)
    {
        int walker = n - 1;
        sorted = true;
        while (walker > current)
        {
            if (list[walker] < list[walker - 1])
            {
                sorted = false;
                Exchange(list[walker], list[walker - 1]);
            }
            walker--;
        }
        current++;
    }
}
int main()
{
    int n;
    cout << "Enter the number of array elements" << endl;
    cin >> n;
    int *arr = new int[n];
    cout << "Enter array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    cout << "Before sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    Bubblesort(arr, n);
    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}