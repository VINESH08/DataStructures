#include <iostream>
#include <climits>
using namespace std;

class MaxSubArray
{
private:
    int *arr;
    int size;

public:
    MaxSubArray(int n) : size(n), arr(new int[n]) {}

    void input()
    {
        cout << "Enter the array elements:\n";
        for (int i = 0; i < size; i++)
        {
            cin >> arr[i];
        }
    }

    void FindMaxSubarray(int low, int high, int &start, int &end, int &max_sum)
    {
        if (low == high)
        {
            start = end = low;
            max_sum = arr[low];
        }
        else
        {
            int mid = (low + high) / 2;
            int l_start, l_end, l_max_sum;
            int r_start, r_end, r_max_sum;
            int c_start, c_end, c_max_sum;

            FindMaxSubarray(low, mid, l_start, l_end, l_max_sum);
            FindMaxSubarray(mid + 1, high, r_start, r_end, r_max_sum);
            FindCrossSum(low, mid, high, c_start, c_end, c_max_sum);

            if (l_max_sum >= r_max_sum && l_max_sum >= c_max_sum)
            {
                start = l_start;
                end = l_end;
                max_sum = l_max_sum;
            }
            else if (r_max_sum >= l_max_sum && r_max_sum >= c_max_sum)
            {
                start = r_start;
                end = r_end;
                max_sum = r_max_sum;
            }
            else
            {
                start = c_start;
                end = c_end;
                max_sum = c_max_sum;
            }
        }
    }

    void FindCrossSum(int low, int mid, int high, int &start, int &end, int &cross_sum)
    {
        int left_sum = INT_MIN, right_sum = INT_MIN;
        int sum = 0;
        int max_left = mid, max_right = mid + 1;

        for (int i = mid; i >= low; i--)
        {
            sum += arr[i];
            if (sum > left_sum)
            {
                left_sum = sum;
                max_left = i;
            }
        }

        sum = 0;
        for (int i = mid + 1; i <= high; i++)
        {
            sum += arr[i];
            if (sum > right_sum)
            {
                right_sum = sum;
                max_right = i;
            }
        }

        start = max_left;
        end = max_right;
        cross_sum = left_sum + right_sum;
    }
};

int main()
{
    int n, start, end, max_sum;
    cout << "Enter the size of the array:\n";
    cin >> n;
    MaxSubArray obj(n);
    obj.input();
    obj.FindMaxSubarray(0, n - 1, start, end, max_sum);
    cout << "Start: " << start + 1 << "\n";
    cout << "End: " << end + 1 << "\n";
    cout << "Sum: " << max_sum << "\n";
    return 0;
}
