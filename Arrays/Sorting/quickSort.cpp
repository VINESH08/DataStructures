#include <iostream>
#include <vector>
using namespace std;
void quickSort(vector<int> &arr, int startindex, int endindex)
{
    if (startindex >= endindex)
        return;
    int pivot = startindex;
    int leftpoint = startindex + 1;
    int rightpoint = endindex;
    while (leftpoint <= rightpoint)
    {
        if (arr[leftpoint] > arr[pivot] && arr[rightpoint] < arr[pivot])
        {
            swap(arr[leftpoint], arr[rightpoint]);
        }
        if (arr[leftpoint] <= arr[pivot])
            leftpoint++;
        if (arr[rightpoint] > arr[pivot])
            rightpoint--;
    }
    swap(arr[pivot], arr[rightpoint]);
    bool leftsubarr = (rightpoint - 1) - startindex < endindex - (rightpoint + 1);
    if (leftsubarr)
    {
        quickSort(arr, startindex, rightpoint - 1);
        quickSort(arr, rightpoint + 1, endindex);
    }
    else
    {
        quickSort(arr, rightpoint + 1, endindex);
        quickSort(arr, startindex, rightpoint - 1);
    }
}
int main()
{
    int ar[] = {8, 5, 2, 3, 5, 6, 9};
    std::vector<int> arr(ar, ar + sizeof(ar) / sizeof(ar[0]));
    quickSort(arr, 0, arr.size() - 1);
    for (auto i : arr)
    {
        cout << i << " ";
    }
    cout << endl;
}