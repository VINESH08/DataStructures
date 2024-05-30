#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
#include <string>
using namespace std;
class LCSTD // top down approch
{
private:
    int rows;
    int columns;
    int **arr;
    char **sym;

public:
    LCSTD(int row, int col)
    {
        rows = row;
        columns = col;
        arr = new int *[row];
        sym = new char *[row];
        for (int i = 0; i < row; i++)
            arr[i] = new int[col];
        for (int i = 0; i < row; i++)
            sym[i] = new char[col];
        for (int i = 0; i < rows; i++)
        {
            for (int j = 0; j < columns; j++)
            {
                arr[i][j] = -1;
            }
        }
    }
    int lcstd(string x, string y, int i, int j)
    {
        if (arr[i][j] > 0)
            return arr[i][j];
        if (i == 0 || j == 0)
        {
            arr[i][j] = 0;
            return arr[i][j];
        }
        if (x[i - 1] == y[j - 1])
        {
            arr[i][j] = 1 + lcstd(x, y, i - 1, j - 1);
        }
        else
        {
            int t1 = lcstd(x, y, i - 1, j);
            int t2 = lcstd(x, y, i, j - 1);
            if (t1 >= t2)
            {
                arr[i][j] = t1;
                sym[i][j] = 'u';
            }
            else
            {
                arr[i][j] = t2;
                sym[i][j] = 'l';
            }
        }
        return arr[i][j];
    }
};
int main()
{

    string s1, s2;
    // cout << "Enter the number of rows" << endl;
    // cin >> n;
    // cout << "Enter the number of columns" << endl;
    // cin >> m;
    cout << "Enter the String one" << endl;
    cin >> s1;
    cout << "Enter the String two" << endl;
    cin >> s2;
    // cout << s1.length();
    LCSTD obj(s1.length() + 1, s2.length() + 1);
    cout << obj.lcstd(s1, s2, s1.length(), s2.length()) << endl;
}