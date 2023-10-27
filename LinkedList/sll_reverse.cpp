#include <iostream>
using namespace std;
struct node
{
    int data;
    struct node *link;
};
void add_elements(struct node *&head, int ele)
{
    struct node *temp = (struct node *)malloc(sizeof(struct node));
    temp->data = ele;
    temp->link = NULL;
    if (head == NULL)
    {
        head = temp;
        return;
    }
    struct node *ptr = head;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
void printele(struct node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty" << endl;
    }
    struct node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->link;
    }
}
void rever(struct node *&head)
{
    struct node *ptr1 = NULL;
    struct node *ptr2 = head;
    while (ptr2 != NULL)
    {
        ptr2 = head->link;
        head->link = ptr1;
        ptr1 = head;
        head = ptr2;
    }
    head = ptr1;
}
int main()
{
    struct node *head = NULL;
    int n, dat;
    cout << "enter the number of elements" << endl;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> dat;
        add_elements(head, dat);
    }
    printele(head);
    cout << endl;
    rever(head);
    printele(head);
}