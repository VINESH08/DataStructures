#include <iostream>
#include <math.h>
#include <chrono>
using namespace std;
class Solution
{
public:
    int minJumps(int arr[], int n)
    {
        // Your code here
        return round(n / 5 + 0.5) * 5;
    }
};
int main()
{
    // cout << "Hellomain";
    Solution obj;
    // cout << "Hellomain";
    int arr[] = {1, 3, 5, 8, 9, 2, 6, 7, 6, 8, 9};

    int ans = obj.minJumps(arr, 73);
    cout << ans << endl;
}