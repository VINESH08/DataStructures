#include <iostream>
#include <limits.h>
using namespace std;
int RIGHT(int i);
void HeapSort(int arr[], int n);
void BuildMaxHeap(int arr[], int n);
void MaxHeapify(int arr[], int n);
int LEFT(int i);
void Exchange(int &a, int &b);
void Exchange(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}
int heapSize;
int main()
{
    int n;
    cout << "Enter the size of the array" << endl;
    cin >> n;
    heapSize = n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    HeapSort(arr, n);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
}

void HeapSort(int arr[], int n)
{

    BuildMaxHeap(arr, n);
    for (int i = n - 1; i >= 1; i--)
    {
        Exchange(arr[0], arr[i]);
        heapSize--;
        MaxHeapify(arr, 0);
    }
    // Exchange(arr[0], arr[1]);
}

void BuildMaxHeap(int arr[], int n)
{

    heapSize = n;
    int i;

    for (i = (heapSize / 2) - 1; i >= 0; i--)
    {

        MaxHeapify(arr, i);
    }
}

void MaxHeapify(int arr[], int i)
{
    int largest = i;
    int l = LEFT(i);
    int r = RIGHT(i);
    if (l <= (heapSize - 1) && arr[l] > arr[i])
        largest = l;
    if (r <= (heapSize - 1) && arr[r] > arr[largest])
        largest = r;

    if (largest != i)
    {
        Exchange(arr[i], arr[largest]);
        MaxHeapify(arr, largest);
    }
}
int LEFT(int i)
{
    return (2 * i) + 1;
}
int RIGHT(int i)
{
    return (2 * i) + 2;
}
