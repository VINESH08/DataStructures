#include <vector>
#include <iostream>
using namespace std;
class SlidingWindow
{
private:
    int currsum;
    int maxsum;
    int size;
    int *arr;

public:
    SlidingWindow(int n)
    {
        currsum = 0;
        maxsum = INT_MIN;
        size = n;
        arr = new int[n];
    }
    void input()
    {

        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }
    int sliding(int k)
    {

        for (int i = 0; i < k; i++)
            currsum += arr[i];
        maxsum = currsum;
        for (int i = k; i < size; i++)
        {
            currsum = currsum - arr[i - k] + arr[i];
            maxsum = max(currsum, maxsum);
        }
        return maxsum;
    }
};
int main()
{
    int k, n;
    cout << "Enter the k value" << endl;
    cin >> k;
    cout << "Enter the size of array" << endl;
    cin >> n;
    SlidingWindow obj(n);
    obj.input();
    cout << obj.sliding(k) << endl;
}