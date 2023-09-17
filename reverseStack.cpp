//reverse a stack without using a temporary stack
#include <iostream>
#include <stack>
using namespace std;
void insertAtbottom(stack<int> &st, int val)
{
    if (st.empty())
    {
        st.push(val);
        return;
    }
    int ele = st.top();
    st.pop();
    insertAtbottom(st, val);
    st.push(ele);
}
void reverse(stack<int> &st)
{
    if (st.empty())
    {
        return;
    }
    int ele = st.top();
    st.pop();
    reverse(st);
    insertAtbottom(st, ele);
}
int main()
{
    stack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    reverse(st);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
}