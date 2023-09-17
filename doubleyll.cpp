#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int va)
    {
        data = va;
        prev = NULL;
        next = NULL;
    }
};
void insertAthead(node *&head, int val)
{
    node *temp = new node(val);
    if (head != NULL)
    {
        head->prev = temp;
        temp->next = head;
    }
    head = temp;
}
void insertAttail(node *&head, int val)
{
    if (head == NULL)
    {
        insertAthead(head, val);
        return;
    }
    node *temp = new node(val);
    node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
    temp->prev = ptr;
}
void disp(struct node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty no elements to display" << endl;
    }
    node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}
int main()
{
    node *head = NULL;
    insertAttail(head, 1);
    insertAttail(head, 2);
    insertAttail(head, 3);
    insertAttail(head, 4);
    insertAttail(head, 5);
    disp(head);
    cout << endl;
    insertAthead(head, 6);
    disp(head);
}