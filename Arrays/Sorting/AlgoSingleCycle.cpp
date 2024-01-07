#include <vector>
#include <iostream>
using namespace std;
int getindex(vector<int> v, int currindex);
bool SingleCheck(vector<int> v)
{
    int currindex = 0;
    int visitedindex = 0;
    while (visitedindex < v.size())
    {
        if (visitedindex > 0 && currindex == 0)
            return false;
        visitedindex++;
        currindex = getindex(v, currindex);
    }
    return currindex == 0;
}
int getindex(vector<int> v, int currindex)
{
    int nxti = v[currindex];
    int nxtindex = (currindex + nxti) % (int)v.size();
    return nxtindex >= 0 ? nxtindex : nxtindex + v.size();
}
int main()
{
    int arr[] = {1, 1, 1, 1, 2};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    bool ans = SingleCheck(v);
    cout << ans << endl;
}