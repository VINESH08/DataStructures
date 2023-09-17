#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *link;
    Node(int val)
    {
        data = val;
        link = NULL;
    }
};
void add_element(Node *&head, int value)
{
    Node *temp = new Node(value);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *ptr = NULL;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void print_elements(Node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty no elements to display" << endl;
    }
    Node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << ' ';
        ptr = ptr->link;
    }
}
void remove_dup(Node *head)
{
    Node *start, *startnext, *dup;
    start = head;
    while (start != NULL && start->link != NULL)
    {
        startnext = start;
        while (startnext->link != NULL)
        {
            if (start->data == startnext->link->data)
            {
                dup = startnext->link;
                startnext->link = startnext->link->link;
                delete (dup);
            }
            else
            {
                startnext = startnext->link;
            }
        }
        start = start->link;
    }
}
int main()
{
    Node *head = NULL;
    add_element(head, 7);
    add_element(head, 8);
    add_element(head, 7);
    add_element(head, 21);
    add_element(head, 8);
    print_elements(head);
    cout << endl;
    remove_dup(head);
    print_elements(head);
}
