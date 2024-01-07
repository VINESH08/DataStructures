#include <iostream>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *link;
    node(int val)
    {
        this->data = val;
        this->link = NULL;
    }
};
node *mergeLL(node *temp1, node *temp2);
void insert(node *&head, int val)
{
    node *newnode = new node(val);
    if (!head)
    {
        head = newnode;
        return;
    }
    node *temp = head;
    while (temp->link != NULL)
    {
        temp = temp->link;
    }
    temp->link = newnode;
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
node *findmid(node *head)
{
    node *slow = head;
    node *fast = head->link;
    while (fast != NULL && fast->link != NULL)
    {
        slow = slow->link;
        fast = fast->link->link;
    }
    return slow;
}
node *SortLL(node *head)
{
    if (head->link == NULL) // single element in LL is always sorted
        return head;
    node *mid = findmid(head);
    node *temp1 = head;
    node *temp2 = mid->link;
    mid->link = NULL;
    return mergeLL(SortLL(temp1), SortLL(temp2));
}
node *mergeLL(node *temp1, node *temp2)
{
    node *ptr, *curr = NULL;
    if (temp1->data < temp2->data)
    {
        ptr = temp1;
        curr = ptr;
        temp1 = temp1->link;
    }
    else
    {
        ptr = temp2;
        curr = ptr;
        temp2 = temp2->link;
    }
    while (temp1 && temp2)
    {
        if (temp1->data < temp2->data)
        {
            curr->link = temp1;
            temp1 = temp1->link;
        }
        else
        {
            curr->link = temp2;

            temp2 = temp2->link;
        }
        curr = curr->link;
    }
    if (temp1)
    {
        curr->link = temp1;
    }
    if (temp2)
    {
        curr->link = temp2;
    }
    return ptr;
}
int main()
{
    node *head = NULL;

    insert(head, 1);
    insert(head, 3);
    insert(head, 5);
    insert(head, 2);
    insert(head, 4);
    cout << "Before Sorting" << endl;
    displayelement(head);
    cout << "After Sorting" << endl;
    node *ans = SortLL(head);
    displayelement(ans);
}