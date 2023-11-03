#include <iostream>
#include <cstring>

using namespace std;
struct node
{
    int data;
    node *link;
};
struct head
{
    node *top;
    int count;
};
class posteval

{
public:
    head *stacklist;
    string evalexpr;
    int c1, c2;
    int op1, op2;
    posteval(string convexpr)
    {
        stacklist = new head();
        stacklist->count = 0;
        stacklist->top = NULL;
        evalexpr = convexpr;
    }
    bool isEmpty()
    {
        if (stacklist->top == NULL)
        {
            return true;
        }
        return false;
    }
    void push(int val)
    {
        node *newnode = new node();
        newnode->data = val;
        newnode->link = stacklist->top;
        stacklist->top = newnode;
    }
    int pop()
    {
        int dataout = stacklist->top->data;
        stacklist->top = stacklist->top->link;
        return dataout;
    }
    char Top()
    {
        return stacklist->top->data;
    }
    int eval()
    {

        for (int i = 0; evalexpr[i] != '\0'; i++)
        {
            char c = evalexpr[i];
            if (isdigit(c))
            {
                int res = c - '0';
                push(res);
            }
            else
            {
                if (c == '+')
                {

                    c2 = pop();
                    c1 = pop();

                    int res = c1 + c2;

                    push(res);
                }
                else if (c == '-')
                {
                    c2 = pop();
                    c1 = pop();

                    int res = c1 - c2;
                    push(res);
                }
                else if (c == '/')
                {
                    c2 = pop();
                    c1 = pop();

                    int res = c1 / c2;
                    push(res);
                }
                else if (c == '*')
                {
                    c2 = pop();
                    c1 = pop();

                    int res = c1 * c2;
                    //  cout << res << endl;
                    push(res);
                }
            }
        }
        int result = pop();
        // cout << c << endl;
        return result;
    }
};
int main()
{
    string exp;
    cout << "Enter the postfix expression" << endl;
    cin >> exp;
    posteval obj(exp);
    cout << obj.eval() << endl;
}