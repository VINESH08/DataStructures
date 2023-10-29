// Programm to create a Linked list using function call
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link; // link is a self referential pointer..
    node(int val)
    {
        data = val;
        link = NULL;
    }
};
void insertAtTail(node *&head, int val)
{
    node *temp = new node(val); // new pointer creates memory for the node class data types
    if (head == NULL)
    {
        head = temp;
        return; // specifically used because to end the insertAtTail function and go to main.
    }
    node *ptr = NULL;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void displayelement(node *head)
{
    node *ptr1 = NULL;
    ptr1 = head;
    while (ptr1 != NULL)
    {
        cout << ptr1->data << ' ';
        ptr1 = ptr1->link;
    }
    cout << endl;
}
int main()
{
    node *head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    displayelement(head);
}