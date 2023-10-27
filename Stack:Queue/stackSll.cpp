#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int val)
    {
        data = val;
        link = NULL;
    }
};
bool isEmpty(node *&head)
{
    if (head == NULL)
        return true;
}
void push(node *&head, int val)
{
    node *temp = new node(val);
    if (isEmpty(head))
    {
        head = temp;
        return;
    }
    temp->link = head;
    head = temp;
}
int pop(node *&head)
{
    int val = head->data;
    head = head->link;
    return val;
}
int gettop(node *&head)
{
    int val = head->data;
    return val;
}
int main()
{
    node *head = NULL;
    int choice;
    do
    {
        cout << "enter your choice" << endl;
        cout << "1.To push" << endl;
        cout << "2.To pop" << endl;
        cout << "3.To seek the top" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            int val;
            cout << "Enter the value" << endl;
            cin >> val;
            push(head, val);
            break;
        case 2:
            cout << pop(head) << endl;
            break;
        case 3:
            cout << gettop(head) << endl;
            break;
        default:
            cout << "enter the proper choice!" << endl;
        }

    } while (choice != 0);
}