#include <iostream>
#include <string>
using namespace std;
struct pitable
{
    char c;
    int num;
};
class KMP
{
private:
    pitable *pi;

public:
    void prefixFunction(string patt)
    {
        pi = new pitable[patt.length()];
        int k = -1;
        pi[0].num = -1;

        for (int i = 0; i < patt.length(); i++)
        {
            pi[i].c = patt[i];
        }
        int m = patt.length();
        for (int q = 1; q <= m - 1; q++)
        {

            while (k > -1 && patt[k + 1] != patt[q])
            {
                k = pi[k].num;
            }
            if (patt[k + 1] == patt[q])
                k++;
            pi[q].num = k;
        }
    }
    void stringMatcher(string text, string p)
    {
        int n = text.length();
        int m = p.length();
        int j = -1;
        for (int i = 0; i < n; i++) // Time Complexity would be O(n+m)
        {
            while (j > -1 && p[j + 1] != text[i])
            {
                j = pi[j].num;
            }
            if (p[j + 1] == text[i])
            {
                j++;
            }
            if (j == m - 1)
            {
                cout << "Pattern Occurs at valid shift:" << i - m + 2 << endl;
                j = pi[j].num;
            }
        }
    }
};
int main()
{
    KMP obj;
    obj.prefixFunction("ababd");
    obj.stringMatcher("zababd", "ababd");
}