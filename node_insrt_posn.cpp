#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
void add_ele(struct node *&head, int value)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->link = NULL;
    temp->data = value;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void insertAt(struct node *head, int valin, int valaf)
{
    struct node *ptr = NULL;
    ptr = head;
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = valin;
    temp->link = NULL;
    while (ptr->data != valaf)
    {
        ptr = ptr->link;
    }
    struct node *jum = NULL;
    jum = ptr;
    jum = jum->link;
    ptr->link = NULL;
    ptr->link = temp;
    temp->link = jum;
}
void disp(struct node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty no elements to display" << endl;
    }
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << endl;
        ptr = ptr->link;
    }
}

int main()
{
    struct node *head = NULL;
    add_ele(head, 1);
    add_ele(head, 2);
    add_ele(head, 3);
    add_ele(head, 5);
    disp(head);
    //  cout << head->data << endl;
    //cout << head->link->data << endl;

    cout << "--------------" << endl;
    insertAt(head, 4, 3);
    disp(head);
}