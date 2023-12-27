#include <iostream>
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
node *add2ll(node *head1, node *head2)
{
    node *temp1 = head1;
    node *temp2 = head2;
    node *dummy = new node(-1);
    node *temp = dummy;
    int carry = 0, sum;
    while (temp1 != NULL || temp2 != NULL)
    {
        sum = carry;
        if (temp1)
            sum = sum + temp1->data;
        if (temp2)
            sum = sum + temp2->data;
        carry = sum / 10;
        sum = sum % 10;
        node *newnode = new node(sum);
        temp->link = newnode;
        temp = temp->link;

        if (temp1)
            temp1 = temp1->link;
        if (temp2)
            temp2 = temp2->link;
    }
    if (carry)
    {
        node *newnode = new node(carry);
        temp->link = newnode;
        temp = temp->link;
    }
    return dummy->link;
}
int main()
{
    node *head1 = NULL;
    insert(head1, 4);
    insert(head1, 5);
    insert(head1, 9);
    insert(head1, 9);
    displayelement(head1);
    node *head2 = NULL;
    insert(head2, 3);
    insert(head2, 5);
    displayelement(head2);
    node *head3 = add2ll(head1, head2);
    displayelement(head3);
}