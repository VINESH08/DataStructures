/*problem: given an linked list reverse only the even subparts of the linked list
displaying the odd as such but the even contigious integer must be reversed.*/

#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int value)
    {
        data = value;
        next = NULL;
    }
};
void insertAt(Node *&head, int val)
{
    Node *temp = new Node(val);
    if (head == NULL)
    {
        head = temp;
        return;
    }
    Node *ptr = head;
    while (ptr->next != NULL)
    {
        ptr = ptr->next;
    }
    ptr->next = temp;
}
void insertHead(Node *&head2, int valu)
{
    Node *n = new Node(valu);
    n->next = head2;
    head2 = n;
}
void display(Node *head)
{
    Node *ptr = head;
    while (ptr != NULL)
    {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
}

void revll(Node *&head)
{
    Node *temp = head;
    while (temp->next != NULL)
    {
        if (temp->data % 2 == 0)
        {
            Node *head2 = NULL;
            while ((temp->data % 2 == 0) && (temp->next != NULL))
            {
                insertHead(head2, temp->data);
                temp = temp->next;
            }
            if (temp->data % 2 == 0)
            {
                insertHead(head2, temp->data);
            }
            display(head2);
        }
        else
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    if ((temp->next == NULL) && temp->data % 2 != 0)
    {
        cout << temp->data << " ";
    }
}
int main()
{
    int n, dat;
    cin >> n;
    Node *head = NULL;
    for (int i = 0; i < n; i++)
    {
        cin >> dat;
        insertAt(head, dat);
    }
    revll(head);
}
