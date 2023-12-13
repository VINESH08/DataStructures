#include <iostream>
#define max 5
using namespace std;
class STACK
{
private:
    int top = -1;
    int stack[max];

public:
    bool isfull()
    {
        if (top == max)
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if (top == -1)
            return true;

        else

            return false;
    }
    void push(int data)
    {
        if (isfull())
        {
            cout << "Stack is full" << endl;
            // return false;
        }
        else
        {
            top++;
            stack[top] = data;

            // return true;
        }
    }
    void pop()
    {
        if (isempty())
        {
            cout << "stack is empty!" << endl;
            // return false;
        }
        else
        {
            int dataout = stack[top];
            top--;
            cout << dataout << endl;
            // return true;
        }
    }
    void stacktop()
    {
        if (isempty())
        {
            cout << "stack is empty no element to peep into" << endl;
            // return false;
        }
        else
        {
            int dataout = stack[top];
            cout << "element at top is:" << dataout << endl;
            // return true;
        }
    }
};
int main()
{
    STACK s;
    int choice;
    cout << "enter your choice" << endl;
    do
    {

        cout << "1.To push the element" << endl;
        cout << "2.To pop the element" << endl;
        cout << "3.To see the Stack top element" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the data to be pushed:" << endl;
            int n;
            cin >> n;
            s.push(n);
            break;
        case 2:
            s.pop();
            break;
        case 3:
            s.stacktop();
            break;
        default:
            cout << "enter valid choice" << endl;
            break;
        }
    } while (choice != 0);
}