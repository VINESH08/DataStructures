#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    int data;
    node *link;
};
struct node1
{
    string data1;
    node1 *link1;
};
struct head
{
    node *first;
    int count;
};
struct head1
{
    node1 *first1;
    int count1;
};
class sll
{
public:
    head *headnode;
    head1 *headnode1;
    void create()
    {

        headnode = new head();
        headnode->first = NULL;
        headnode->count = 0;
        headnode1 = new head1();
        headnode1->first1 = NULL;
        headnode1->count1 = 0;
    }

    bool Addposition(int position)
    {
        node *newnode = new node();
        newnode->data = position;
        newnode->link = NULL;
        node *ppre = NULL;
        node *ploc = headnode->first;
        while (ploc != NULL && (ploc->data) < position)
        {
            ppre = ploc;
            ploc = ploc->link;
        }
        if (ppre == NULL)
        {
            newnode->link = headnode->first;
            headnode->first = newnode;
            (headnode->count)++;
            return true;
        }
        else
        {
            newnode->link = ppre->link;
            ppre->link = newnode;
            (headnode->count)++;
            return true;
        }
    }
    void display()
    {
        node *temp = headnode->first;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->link;
        }
    }
    void display2()
    {
        node1 *temp = headnode1->first1;
        while (temp != NULL)
        {
            cout << temp->data1 << " ";
            temp = temp->link1;
        }
    }
    bool insertAt(string word, int position)
    {
        node1 *newnode1 = new node1();
        newnode1->data1 = word;
        newnode1->link1 = NULL;
        node1 *ppre = NULL;
        node1 *ploc = headnode1->first1;
        if (ploc == NULL || position == 1)
        {
            newnode1->link1 = ploc;
            headnode1->first1 = newnode1;

            return true;
        }
        while (position != 2 && ploc != NULL)
        {
            ppre = ploc;
            ploc = ploc->link1;
            position--;
        }

        newnode1->link1 = ploc->link1;
        ploc->link1 = newnode1;

        return true;
    }
};
int main()
{
    sll p, l2, l1;
    p.create();
    l2.create();
    l1.create();
    p.Addposition(3);
    p.Addposition(4);
    // p.Addposition(5);
    p.display();
    cout << endl;
    l1.insertAt("FAILED", 1);
    l1.insertAt("DSLAB", 2);
    l1.insertAt("IN", 2);
    l1.insertAt("I", 1);
    l1.insertAt("WILL", 2);
    l1.insertAt("BE", 3);
    l1.display2();
    cout << endl;
    l2.insertAt("Grade", 1);
    l2.insertAt("Get", 1);
    l2.insertAt("S", 2);
    l2.display2();
    // l1.display2();
}