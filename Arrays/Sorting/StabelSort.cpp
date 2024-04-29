#include <iostream>
#include <string>
using namespace std;
class Data
{
private:
    string city;
    string state;

public:
    Data(string city, string state)
    {
        this->city = city;
        this->state = state;
    }
    string getcity()
    {
        return city;
    }
    string getstate()
    {
        return state;
    }
    static void heapsort(Data **&ob, int n)
    {
        for (int i = (n / 2) - 1; i >= 0; i--)
        {
            heapify(ob, i, n);
        }
        for (int i = n - 1; i >= 1; i--)
        {
            swap(ob[0], ob[i]);
            n--;
            heapify(ob, 0, n);
        }
    }
    static void heapify(Data **&ob, int i, int n) // sort only states
    {
        int largest = i;
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if (left <= n && ob[left]->getstate().compare(ob[largest]->getstate()) > 0)
        {
            largest = left;
        }
        if (right <= n && ob[right]->getstate().compare(ob[largest]->getstate()) > 0)
        {
            largest = right;
        }
        if (largest != i)
        {
            swap(ob[i], ob[largest]);
            heapify(ob, largest, n);
        }
    }
    static void quicksort(Data **&ob, int p, int r)
    {
        if (p < r)
        {
            int k = partation(ob, p, r);
            quicksort(ob, p, k - 1);
            quicksort(ob, k + 1, r);
        }
    }
    static int partation(Data **&ob, int p, int q)
    {
        Data *pivot = ob[q];
        int i = p - 1;
        for (int j = p; j <= q - 1; j++)
        {
            if (ob[j]->getstate() == pivot->getstate() && ob[j]->getcity() < pivot->getcity())
            {
                i++;
                swap(ob[i], ob[j]);
            }
        }
        swap(ob[i + 1], ob[q]);
        return i + 1;
    }
};
int main()
{
    string cit;
    string stat;
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    Data **ob = new Data *[n];
    for (int i = 0; i < n; i++)
    {
        cout << "Enter city" << endl;
        cin >> cit;
        cout << "Enter the state" << endl;
        cin >> stat;
        ob[i] = new Data(cit, stat);
    }
    Data::heapsort(ob, n);
    Data::quicksort(ob, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        cout << "City:" << ob[i]->getcity() << " State:" << ob[i]->getstate() << endl;
    }
}