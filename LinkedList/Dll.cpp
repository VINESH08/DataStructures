#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *prev;
};
struct ListHead
{
    int count;
    node *head;
    node *rear;
};
class Dll
{
public:
    ListHead *Dllhead;
    node *ploc;
    Dll()
    {
        Dllhead = new ListHead();
        Dllhead->count = 0;
        Dllhead->head = NULL;
        Dllhead->rear = NULL;
    }
    bool isEmpty()
    {
        if (Dllhead->count == 0)
            return true;
        return false;
    }
    void Insert(int val)
    {
        node *newnode = new node();
        newnode->data = val;
        if (isEmpty())
        {
            Dllhead->head = newnode;
            Dllhead->rear = newnode;
            (Dllhead->count)++;
            return;
        }
        Dllhead->rear->next = newnode;
        newnode->prev = Dllhead->rear;
        Dllhead->rear = newnode;
        (Dllhead->count)++;
    }
    bool Delete(int val)
    {
        if (Search(val))
        {
            if (ploc->prev != NULL)
                ploc->prev->next = ploc->next;
            else
                Dllhead->head = ploc->next;
            if (ploc->next != NULL)
                ploc->next->prev = ploc->prev;
            else
                Dllhead->rear = ploc->prev;
            (Dllhead->count)--;
            delete (ploc);
            return true;
        }
        return false;
    }
    bool Search(int target)
    {
        ploc = Dllhead->head;
        while (ploc != NULL && ploc->data != target)
        {
            ploc = ploc->next;
        }
        if (ploc == NULL)
            return false;

        return true;
    }
    void Display()
    {
        node *temp = Dllhead->head;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
};
int main()
{
    Dll obj;
    obj.Insert(1);
    obj.Insert(2);
    obj.Insert(3);
    obj.Insert(4);
    obj.Display();

    obj.Delete(7);
    if (obj.Search(6))
        cout << "Found" << endl;
    else
        cout << "Not found" << endl;

    obj.Display();
}
