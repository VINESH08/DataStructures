#include <iostream>
using namespace std;
int maxsub(int arr[], int size)
{
    int maxsum = arr[0];
    int sum = arr[0];
    for (int i = 1; i < size; i++)
    {
        if (sum >= 0)
        {
            sum = sum + arr[i];
        }
        else
        {
            sum = arr[i];
        }
        if (sum > maxsum)
            maxsum = sum;
    }
    return maxsum;
}
int main()
{
    int n;
    cout << "enter the size :" << endl;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int max = maxsub(arr, n);
    cout << max << endl;
    ;
}