#include <iostream>
using namespace std;
void number_of_nodes(struct node *head);
void print_elements(struct node *head);
struct node
{
    int data;
    struct node *link;
};
void print_elements(struct node *head)
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
void number_of_nodes(struct node *head)
{
    if (head == NULL)
    {
        cout << "linked list is empty no nodes are found" << endl;
    }
    int count = 0;
    struct node *ptr = NULL;
    ptr = head;
    while (ptr != NULL)
    {
        count++;
        ptr = ptr->link;
    }
    cout << "number of nodes is: " << count << endl;
}
int main()
{
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 45;
    head->link = NULL;
    struct node *current = NULL;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 54;
    head->link = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 90;
    current->link = NULL;
    head->link->link = current;
    number_of_nodes(head);
    print_elements(head);
}