#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>

using namespace std;
class InsertionSort
{
private:
    int size;
    int *arr;
    int count;

public:
    InsertionSort(int len)
    {
        size = len;
        arr = new int[len];
    }
    void Sort()
    {
        count = 0;
        for (int i = 1; i < size; i++)
        {
            count++;
            int key = arr[i];
            int j = i - 1;
            while (j >= 0 && arr[j] > key)
            {
                arr[j + 1] = arr[j];
                j--;
                count++;
            }
            arr[j + 1] = key;
        }
    }
    void input()
    {

        ifstream inf; // srand((long int)clock())
                      // for(i=0;i<size;i++)
                      // arr[i]=rand()%30000
        inf.open("output.txt");
        // ascending order
        srand((long int)clock());
        for (int i = 0; i < size; i++)
            // arr[i] = rand() % 30000;->random
            inf >> arr[i]; // ascending
        for (int i = 0, j = size - 1; i < j; i++, j--)
        {
            int t = arr[i];
            arr[i] = arr[j];
            arr[j] = t;
        }
        // fou.close();
        // sort(arr.begin(), arr.end());
    }
    void display()
    {
        ofstream outdata("desoup.txt");

        if (outdata)
        {
            for (int i = 0; i < size; i++)
            {
                outdata << arr[i] << "\t";
            }
            outdata.close();
        }
        cout << "Value of count: " << count << endl;
    }
};
int main()
{
    int n;
    cout << "Enter the size" << endl;
    cin >> n;
    InsertionSort obj(n);
    ofstream fou("input.txt");
    srand((long int)clock());
    for (int i = 0; i < 10000; i++)
        fou << rand() % 30000 << "\t";
    fou.close();

    obj.input();
    obj.Sort();
    obj.display();
}
