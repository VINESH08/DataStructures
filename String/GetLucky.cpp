#include <iostream>
#include <string>
using namespace std;

class Solution
{
public:
    int getLucky(string s, int k)
    {
        int sum = 0;
        string result;
        for (char c : s)
        {
            result += to_string(c - 96);
        }
        cout << "String to integer" << result << endl;
        while (k--)
        {
            sum = 0;
            for (char c : result)
            {
                sum += c - '0';
            }
            cout << sum << endl;
            result = to_string(sum);
        }
        return sum;
    }
};
int main()
{
    Solution s;
    cout << s.getLucky("iiii", 1) << endl;
}