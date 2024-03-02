#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <time.h>
#include <cstring>
using namespace std;
class LCS
{
private:
    int rows;
    int columns;
    int **arr;
    char **sym; // symbol array

public:
    LCS(int row, int col)
    {
        rows = row;
        columns = col;
        arr = new int *[row];
        sym = new char *[row];
        for (int i = 0; i < row; i++)
            sym[i] = new char[col];
        for (int i = 0; i < row; i++)
            arr[i] = new int[col];
    }
    void lcsBu(string x, string y)
    {
        for (int i = 0; i < rows; i++)
            arr[i][0] = 0;
        for (int i = 0; i < columns; i++)
            arr[0][i] = 0;
        for (int i = 1; i < rows; i++)
        {
            for (int j = 1; j < columns; j++)
            {
                if (x[i - 1] == y[j - 1])
                {
                    arr[i][j] = 1 + arr[i - 1][j - 1];
                    sym[i][j] = 'd'; // d->diagonal
                }
                else if (arr[i - 1][j] >= arr[i][j - 1])
                {
                    arr[i][j] = arr[i - 1][j];
                    sym[i][j] = 'u'; // u->upper
                }
                else
                {
                    arr[i][j] = arr[i][j - 1];
                    sym[i][j] = 'l'; // l->left
                }
            }
        }
    }
    void print(string x, string y, int i, int j)
    {
        if (i == 0 || j == 0)
            return;
        if (sym[i][j] == 'd')
        {
            print(x, y, i - 1, j - 1);
            cout << x[i - 1] << " ";
        }
        else if (sym[i][j] == 'l')
            print(x, y, i, j - 1);
        else
            print(x, y, i - 1, j);
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
    LCS obj(s1.length() + 1, s2.length() + 1);
    obj.lcsBu(s1, s2);
    obj.print(s1, s2, s1.length(), s2.length());
}