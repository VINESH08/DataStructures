#include <iostream>
using namespace std;
void node_at_end(struct node *head, int data);
void print_elements(struct node *head);
struct node
{
    int data;
    struct node *link;
};
void node_at_end(struct node *head, int data)
{
    struct node *ptr = NULL;
    ptr = head;
    struct node *temp = NULL;
    temp = (struct node *)malloc(sizeof(struct node));
    temp->data = data;
    temp->link = NULL;
    while (ptr->link != NULL)
    {
        ptr = ptr->link;
    }
    ptr->link = temp;
}
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
int main()
{
    int n;
    struct node *head = NULL;
    head = (struct node *)malloc(sizeof(struct node));
    head->data = 34;
    head->link = NULL;
    struct node *current = NULL;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 67;
    current->link = NULL;
    head->link = current;
    current = (struct node *)malloc(sizeof(struct node));
    current->data = 54;
    current->link = NULL;
    head->link->link = current;
    cout << "enter the element you want to add at the end of the node: " << endl;
    cin >> n;
    //call node_at_end function to add one more node at the end
    node_at_end(head, n);
    print_elements(head);
}
/*
    the above code has a time complexity of o(n)we can still optimise the node_at_end
functions time complexity from o(n) to o(1) by eleminating the while loop as follows;;
       struct node node_at_end(struct node* ptr,int data){
            struct node* temp=(struct node*)malloc(sizeof(struct node));
            temp->data=data;
            temp->link=NULL;
            ptr->link=temp;
            return temp;
        }
        int main(){
            struct node* head=(sturct node*)malloc(sizeof(struct node));
            struct node* ptr=NULL;
            ptr=head;
            ptr=node_at_end(ptr,45);        pointer moves to new node
            ptr=node_at_end(ptr,8);          pointer moves to secońd new node
            ptr=node_at_end(ptr,5);        
        }















    */