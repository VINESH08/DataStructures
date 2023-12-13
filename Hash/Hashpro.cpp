#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
};
struct Listhead
{
    int count;
    node *head;
};
class HashPro
{
public:
    int k;
    Listhead **hasharr; // array of pointers
    HashPro(int n)
    {
        hasharr = new Listhead *[n]; // dynamic memory allocation
        for (int i = 0; i < n; i++)
        {
            hasharr[i] = new Listhead();
            hasharr[i]->count = 0;
            hasharr[i]->head = NULL;
        }
    }
    void insert(int val, int size)
    {
        node *ppre, *ploc = NULL;
        k = val % size;
        bool found = search(ppre, ploc, val, k);
        node *newnode = new node();
        newnode->data = val;
        newnode->next = NULL;
        if (!found)
        {
            if (ppre == NULL)
            {
                if (hasharr[k]->count == 0)
                {
                    hasharr[k]->head = newnode;
                }
                else
                {
                    newnode->next = hasharr[k]->head;
                    hasharr[k]->head = newnode;
                }
            }
            else
            {
                ppre->next = newnode;
                newnode->next = ploc;
            }
            hasharr[k]->count++;
        }
    }
    bool Delete(int val, int size)
    {
        node *ppre, *ploc = NULL;
        k = val % size;
        bool found = search(ppre, ploc, val, k);
        if (found)
        {
            if (ppre == NULL)
            {
                hasharr[k]->head = ploc->next;
            }
            else
            {
                ppre->next = ploc->next;
            }
            delete ploc;
            hasharr[k]->count--;
            return true;
        }
        return false;
    }

    bool search(node *&ppre, node *&ploc, int target, int k)
    {
        ppre = NULL;
        ploc = hasharr[k]->head;
        while (ploc != NULL && target != ploc->data)
        {
            ppre = ploc;
            ploc = ploc->next;
        }
        if (ploc == NULL)
            return false;
        else if (target == ploc->data)
            return true;
        return false;
    }
    void display(int k)
    {
        node *temp = hasharr[k]->head;
        cout << "For index:" << k << "   ";
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()
{
    int n, val, ele;
    cout << "Enter the size of hash table" << endl;
    cin >> n;
    HashPro obj(n);
    cout << "Enter the number of values to be inserted" << endl;
    cin >> ele;
    cout << "Enter the values";
    for (int i = 0; i < ele; i++)
    {
        cin >> val;
        obj.insert(val, n);
    }
    cout << "The elements in hash table are" << endl;
    for (int i = 0; i < n; i++)
    {
        obj.display(i);
    }
    cout << "Enter the value to be deleted" << endl;
    cin >> val;
    obj.Delete(val, n);
    cout << "The elements in hash table after deletion are" << endl;
    for (int i = 0; i < n; i++)
    {
        obj.display(i);
    }
}