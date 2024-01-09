#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;
void reversestr(vector<string> &words);
// string reverseWordsInString(string str)
// {
//     // Write your code here.
//     if (str.length() == 0)
//         return "";
//     string temp = "";
//     string ans = "";
//     stack<string> st;
//     // cout << temp.empty();
//     for (char ch : str)
//     {
//         if (ch == ' ')
//         {
//             if (!temp.empty())
//             {
//                 st.push(temp);
//                 temp.clear();
//             }
//         }
//         else
//             temp += ch;
//     }
//     if (!temp.empty())
//     {
//         st.push(temp);
//     }
//     while (!st.empty())
//     {
//         ans += st.top();
//         ans += " ";
//         st.pop();
//     }
//     return ans;
// }
// TimeComplexity-O(N),SpaceComplexity O(N)
string reverseWordsInString(string str)
{
    vector<string> words;
    int startindex = 0;
    int i = 0;
    for (; i < str.length(); i++)
    {
        if (str[i] == ' ')
        {
            words.push_back(str.substr(startindex, i - startindex));
            startindex = i;
        }
        else if (str[startindex] == ' ')
        {
            words.push_back(" ");
            startindex = i;
        }
    }
    words.push_back(str.substr(startindex, i - startindex));
    reversestr(words);
    string ans;
    for (auto it : words)
    {
        ans += it;
    }
    return ans;
}
void reversestr(vector<string> &words)
{
    int start = 0;
    int end = words.size() - 1;
    while (start <= end)
    {
        string temp = words[start];
        words[start] = words[end];
        words[end] = temp;
        start++;
        end--;
    }
}
int main()
{
    cout << reverseWordsInString("b      ");
}