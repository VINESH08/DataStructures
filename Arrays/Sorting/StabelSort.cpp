#include <iostream>
#include <string>

using namespace std;
class Data
{
private:
public:
    string city;
    string state;
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
    static void bubblesort(Data **&ob, int n) // sorting only states(using bubble sort)
    {
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (ob[j]->getstate().compare(ob[j + 1]->getstate()) > 0)
                {
                    Data *temp = ob[j];
                    ob[j] = ob[j + 1];
                    ob[j + 1] = temp;
                }
            }
        }
    }
    static void insertionsort(Data **&ob, int n)
    {
        for (int i = 1; i <= n - 1; i++)
        {
            Data *curr = ob[i];
            string City = ob[i]->getcity();
            string State = ob[i]->getstate();
            int j = i - 1;
            while (j >= 0 && ob[j]->getstate().compare(State) == 0 && ob[j]->getcity().compare(City) > 0)
            {

                ob[j + 1] = ob[j];

                j--;
            }
            ob[j + 1] = curr;
        }
    }
};
int main()
{
    int n;
    cout << "Enter the number of inputs" << endl;
    cin >> n;

    Data **obj = new Data *[n]; // array of pointers
    string city, state;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter the " << i + 1 << " City:" << endl;
        cin >> city;
        cout << "Enter the " << i + 1 << " State:" << endl;
        cin >> state;
        obj[i] = new Data(city, state);
    }
    Data::bubblesort(obj, n);
    Data::insertionsort(obj, n);
    for (int i = 0; i < n; i++)
    {
        cout << "City:" << obj[i]->getcity() << " State:" << obj[i]->getstate() << endl;
    }
}
