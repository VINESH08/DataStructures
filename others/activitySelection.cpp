#include <iostream>
#include <vector>
using namespace std;
struct activity
{
    int start;
    int end;
};
class activitySelection
{
private:
    activity *arr;
    vector<activity> resarr;
    int n;

public:
    activitySelection(int size)
    {
        arr = new activity();

        n = size;
    }
    void input()
    {

        int st;
        int en;
        for (int i = 0; i < n; i++)
        {
            cout << "Enter start:" << endl;
            cin >> st;
            cout << "Enter end:" << endl;
            cin >> en;
            arr[i].start = st;
            arr[i].end = en;
        }
    }
    void Sort()
    {

        for (int i = 1; i < n; i++)
        {
            int key = arr[i].end;
            int key1 = arr[i].start;
            int j = i - 1;
            while (j >= 0 && arr[j].end > key)
            {
                arr[j + 1] = arr[j];
                j--;
            }
            arr[j + 1].end = key;
            arr[j + 1].start = key1;
        }
    }
    void greedyselection()
    {

        resarr.push_back(arr[0]);
        int k = 0;
        for (int m = 1; m < n; m++)
        {
            if (arr[m].start >= arr[k].end)
            {
                resarr.push_back(arr[m]);
                k = m;
            }
        }
    }
    void print()
    {
        for (int i = 0; i < resarr.size(); i++)
        {
            cout << resarr[i].start << "----- " << resarr[i].end << endl;
        }
    }
};
int main()
{
    int si;
    cout << "Enter the size of the array" << endl;
    cin >> si;
    activitySelection obj(si);
    obj.input();
    obj.Sort();
    obj.greedyselection();
    obj.print();
}
