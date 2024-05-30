#include <iostream>
#include <string>
#include <stack>
using namespace std;
class Solution
{
public:
    string reverseWords(string s)
    {
        stack<string> st;
        string str;
        string ans;
        for (char ch : s)
        {

            if (ch == ' ')
            {
                if (str != "")
                    st.push(str);
                str = "";
            }
            else
                str += ch;
        }
        st.push(str);
        // cout << st.top() << endl;
        while (st.size() != 1)
        {
            // cout << st.top() << endl;
            ans = ans + st.top() + " ";
            st.pop();
        }
        ans += st.top();
        return ans;
    }
};
int main()
{
    Solution obj;
    cout << "-----" << endl;
    cout << obj.reverseWords("A GOOD                 EXAMPLE") << endl;
}