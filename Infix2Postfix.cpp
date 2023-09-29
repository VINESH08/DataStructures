#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    char data;
    node *link;
};
struct head
{
    node *top;
    int count;
};
class Infix2post
{
public:
    string preexpr;
    string postfixexpr;
    head *stackhead;
    // A+(B*C)
    Infix2post(string expr)
    {
        preexpr = expr;
    }
    void create()
    {
        stackhead = new head();
        stackhead->count = 0;
        stackhead->top = NULL;
    }
    bool isEmpty()
    {
        if (stackhead->top == NULL)
        {
            return true;
        }
        return false;
    }
    void push(char val)
    {
        node *newnode = new node();
        newnode->data = val;
        newnode->link = stackhead->top;
        stackhead->top = newnode;
    }
    char pop()
    {
        char dataout = stackhead->top->data;
        stackhead->top = stackhead->top->link;
        return dataout;
    }
    char Top()
    {
        return stackhead->top->data;
    }
    int precedence(char c)
    {
        if (c == '+' || c == '-')
            return 1;
        else if (c == '*' || c == '/')
            return 2;
        else if (c == '^')
            return 3;
        else
            return 0;
    }
    void cnvtIn2post()
    {
        for (int i = 0; preexpr[i] != '\0'; i++)

        {
            char character = preexpr[i];
            if (character == '(')
            {
                push('(');
            }
            else if (character == ')')
            {
                char token = pop();
                while (token != '(')
                {
                    postfixexpr += token;
                    token = pop();
                }
            }

            else if (isalnum(character))
            {
                postfixexpr += character;
            }
            else
            {
                if (!isEmpty())
                {
                    // char nxttok = Top();

                    while (!isEmpty() && (precedence(character) <= precedence(Top())))
                    {
                        char token = pop();
                        postfixexpr += token;
                        // nxttok = Top();
                    }
                }
                push(character);
            }
        }
        while (!isEmpty())
        {
            char tok = pop();
            postfixexpr += tok;
        }
        cout << "Postfixexpression is: " << postfixexpr << endl;
    }
};
int main()
{
    cout << "Enter a infix expression" << endl;
    string expr;
    getline(cin, expr);
    Infix2post obj(expr);
    obj.create();
    obj.cnvtIn2post();
}