#include <iostream>
#include <vector>
using namespace std;
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    std::vector<int> v(arr, arr + sizeof(arr) / sizeof(arr[0]));
    for (auto it = v.rbegin(); it != v.rend(); ++it)
    {

        cout << *(it) << " ";
    }
    auto las = prev(v.end(), 6);
    cout << "last element:" << *las << endl;
    cout << v.size() << endl;
    cout << v.back();
}