#include <iostream>
#include <limits.h>
using namespace std;
void mergeSort(int arr[], int p, int r);
void merge(int arr[], int p, int q, int r);
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    int arr[n];
    cout << "Enter the array elements" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    mergeSort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}
void mergeSort(int arr[], int p, int r)
{
    if (p < r)
    {
        int q = (p + r) / 2;
        mergeSort(arr, p, q);
        mergeSort(arr, q + 1, r);
        merge(arr, p, q, r);
    }
}
void merge(int arr[], int p, int q, int r)
{
    int n1 = q - p + 2;
    int n2 = r - q + 1;
    int left[n1];
    int right[n2];
    for (int i = 0; i < (n1 - 1); i++)
        left[i] = arr[p + i];
    left[n1 - 1] = INT_MAX;
    for (int j = 0; j < (n2 - 1); j++)
        right[j] = arr[q + j + 1];
    right[n2 - 1] = INT_MAX;
    int i = 0;
    int j = 0;
    for (int k = p; k <= r; k++)
    {
        if (left[i] <= right[j])
            arr[k] = left[i++];
        else
            arr[k] = right[j++];
    }
}
