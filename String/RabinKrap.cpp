#include <iostream>
#include <string>
using namespace std;
class RabinKrap
{
private:
    int p;
    int d;
    int q;

public:
    RabinKrap(int dv, int qv)
    {
        p = 0;
        d = dv;
        q = qv;
    }
    int charcode(char c)
    {
        return c - 48 + 1;
    }
    void preprocess(string patt)
    {

        for (int i = 0; i < patt.length(); i++)
        {
            p = (p * d + charcode(patt[i])) % q;
        }
    }
    void RkMatcher(string text, string pattern)
    {
        int h = 1;

        // caculating d^m-1 using for loop we get:
        for (int i = 1; i < pattern.length(); i++)
        {
            h = (h * d) % q;
        }
        int t0 = 0;
        for (int i = 0; i < pattern.length(); i++)
        {
            t0 = ((t0 * d) + charcode(text[i])) % q;
        }

        for (int i = 0; i <= text.length() - pattern.length(); i++)
        {
            if (t0 == p)
            {
                int flag = 0;
                for (int j = 0; j < pattern.length(); j++)
                {
                    if (pattern[j] != text[i + j])
                    {
                        flag = 1;
                        break;
                    }
                }
                if (flag == 0)
                {
                    cout << "pattern occurs at valid shift: " << i << endl;
                }
            }
            if (i < text.length() - pattern.length())
            {
                int t1 = ((t0 - (charcode(text[i]) * h)) * d + charcode(text[i + pattern.length()])) % q;
                if (t1 < 0)
                {
                    t1 = t1 + q;
                }
                t0 = t1;
            }
        }
    }
};
int main()
{
    int d;
    int q;
    string t;
    string p;
    cout << "Enter the d value:" << endl;
    cin >> d;
    cout << "Enter the Quotient value" << endl;
    cin >> q;
    cout << "Enter the text" << endl;
    cin >> t;
    cout << "Enter the pattern" << endl;
    cin >> p;
    RabinKrap obj(d, q);
    obj.preprocess(p);
    obj.RkMatcher(t, p);
}