#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *link;
    node(int value)
    {
        data = value;
        link = NULL;
    }
};
void add_element(node *&head, int value)
{
    node *temp = new node(value);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    node *ptr = NULL;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void node_dis(node *&head)
{
    if (head == NULL)
    {
        cout << "Linked list is empty no elements to display" << endl;
    }
    node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << ' ';
        ptr = ptr->link;
    }
}
void delEle(node *&head, int pos)
{
    node *ptr = NULL;
    ptr = head;
    if (head == NULL)
    {
        cout << "The linked list is empty..no elements can be removed.." << endl;
    }
    else if (pos == 1)
    {
        head = ptr->link;
        free(ptr);
        ptr = NULL;
    }
    else
    {
        while (pos != 2)
        {
            ptr = ptr->link;
            pos--;
        }
        ptr->link = ptr->link->link;
        // ptr = ptr->link;
        // free(ptr);
        // ptr = NULL;
    }
}
int main()
{
    node *head = NULL;
    add_element(head, 10);
    add_element(head, 20);
    add_element(head, 30);
    add_element(head, 40);
    add_element(head, 50);
    node_dis(head);
    cout << endl;
    cout << "-------------" << endl;
    delEle(head, 2);
    node_dis(head);
}
