#include <iostream>
using namespace std;
void Exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
void SelectionSort(int arr[], int n)
{
    int small, current;
    current = 0;
    while (current < n - 1)
    {
        int walker = current + 1;
        small = current;
        while (walker < n)
        {
            if (arr[walker] < arr[small])
                small = walker;
            walker++;
        }
        Exchange(arr[current], arr[small]);
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
    SelectionSort(arr, n);
    cout << "after sorting" << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}