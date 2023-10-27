//hapiest day in my life ........................
/*
q)Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.


*/
#include <iostream>
using namespace std;

struct ListNode
{
    int val;
    struct ListNode *next;
};
void addele(struct ListNode *&head, int data)
{
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    n->val = data;
    if (head == NULL)
    {
        head = n;
        return;
    }
    struct ListNode *tem = head;
    while (tem->next != NULL)
    {
        tem = tem->next;
    }
    tem->next = n;
}
void insertHea(struct ListNode *&head2, int value)
{
    struct ListNode *n = (struct ListNode *)malloc(sizeof(struct ListNode));
    n->val = value;
    n->next = head2;
    head2 = n;
}
void reverseBetween(struct ListNode *head, int left, int right)
{
    struct ListNode *cur = head;
    struct ListNode *head2 = NULL;
    struct ListNode *temp = cur;
    int hold = left;
    while (left != 1)
    {
        temp = temp->next;
        left--;
    }
    left = hold;
    while (left <= right)
    {
        insertHea(head2, temp->val);
        temp = temp->next;
        left++;
    }
    cur->next = head2;
    struct ListNode *temp2 = head2;
    while (temp2->next != NULL)
    {
        temp2 = temp2->next;
    }
    temp2->next = temp;
}
void display(struct ListNode *head)
{
    if (head == NULL)
    {
        cout << "no elements to display" << endl;
    }
    struct ListNode *temp = head;
    while (temp != NULL)
    {
        cout << temp->val << " ";
        temp = temp->next;
    }
}
int main()
{
    struct ListNode *head = NULL;
    addele(head, 1);
    addele(head, 2);
    addele(head, 3);
    addele(head, 4);
    addele(head, 5);
    addele(head, 6);
    addele(head, 7);
    addele(head, 8);

    display(head);
    cout << endl;
    reverseBetween(head, 2, 7);
    cout << endl;
    display(head);
}