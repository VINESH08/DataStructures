#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
    node *back;
};
struct Listhead
{
    int count;
    node *front;
    node *rear;
};
class Cdll
{
public:
    Listhead *Cdllhead;
    // node *ppre, *ploc;
    Cdll()
    {
        Cdllhead = new Listhead();
        Cdllhead->count = 0;
        Cdllhead->front = NULL;
        Cdllhead->rear = NULL;
    }
    bool isEmpty()
    {
        if (Cdllhead->count == 0)
            return true;
        return false;
    }
    void Insert(int val)
    {
        node *ppre, *ploc = NULL;
        bool found = Search(ppre, ploc, val);
        if (!found)
        {
            node *newnode = new node();
            newnode->data = val;
            newnode->next = NULL;
            newnode->back = NULL;
            if (ppre == NULL)
            {
                if (isEmpty())
                {
                    Cdllhead->front = newnode;
                    Cdllhead->rear = newnode;
                }
                else
                {
                    Cdllhead->front->back = newnode;
                    Cdllhead->rear->next = newnode;
                }
                newnode->next = Cdllhead->front;
                newnode->back = Cdllhead->rear;
                Cdllhead->front = newnode;
            }
            else
            {
                newnode->back = ppre;
                newnode->next = ploc;
                ppre->next = newnode;
                if (ploc == Cdllhead->front)
                    Cdllhead->rear = newnode;
                else
                    ploc->back = newnode;
            }
            (Cdllhead->count)++;
        }
    }
    bool Search(node *&ppre, node *&ploc, int target)
    {
        if (isEmpty())
            return false;
        ppre = NULL;
        ploc = Cdllhead->front;
        if (ploc->data == target)
            return true;
        if (ploc->data > target)
            return false;
        ppre = ploc;
        ploc = ploc->next;
        while (ploc != Cdllhead->front && target > ploc->data)
        {
            ppre = ploc;
            ploc = ploc->next;
        }
        if (ploc->data == Cdllhead->front->data)
            return false;
        else
        {
            if (target == ploc->data)
                return true;
            else
                return false;
        }
    }
    bool Delete(int val)
    {
        node *ppre, *ploc;
        bool found = Search(ppre, ploc, val);
        if (found)
        {
            if (Cdllhead->count == 1)
            {
                delete Cdllhead->front;
                Cdllhead->front = NULL;
                Cdllhead->rear = NULL;
                (Cdllhead->count)--;
                return true;
            }
            else
            {
                if (ppre == NULL)
                {
                    Cdllhead->front = ploc->next;
                    ploc->next->back = ploc->back;
                    Cdllhead->rear->next = ploc->next;
                }
                else
                {
                    ppre->next = ploc->next;
                    ploc->next->back = ppre;
                    if (ploc->data == Cdllhead->rear->data)
                        Cdllhead->rear = ppre;
                }
                (Cdllhead->count)--;
                delete ploc;
                return true;
            }
        }
        return false;
    }
    void Listcount()
    {
        cout << "Number of nodes:" << Cdllhead->count << endl;
    }
    void Displayfr()
    {
        if (isEmpty())
        {
            cout << "No elements to display" << endl;
        }
        else
        {
            node *temp = Cdllhead->front;
            cout << temp->data << " ";
            temp = temp->next;
            while (temp != Cdllhead->front)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
        }
        cout << endl;
    }
    void Displayrf()
    {
        if (isEmpty())
        {
            cout << "No elements to display" << endl;
        }
        else
        {
            node *temp = Cdllhead->rear;
            cout << temp->data << " ";
            temp = temp->back;
            while (temp != Cdllhead->rear)
            {
                cout << temp->data << " ";
                temp = temp->back;
            }
        }
        cout << endl;
    }
};
int main()
{
    Cdll obj;
    int choice, n, val;
    node *ppre, *ploc = NULL;
    do
    {
        cout << "1.To insert" << endl;
        cout << "2.To Search" << endl;
        cout << "3.To delete" << endl;
        cout << "4.Number of nodes" << endl;
        cout << "5.Display " << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the total values to be inserted" << endl;
            cin >> n;
            cout << "Enter the values" << endl;
            for (int i = 0; i < n; i++)
            {
                cin >> val;
                obj.Insert(val);
            }
            break;
        case 2:
            cout << "Enter the value to be searched:" << endl;
            cin >> val;
            if (obj.Search(ppre, ploc, val))
                cout << "Found: " << val << endl;
            else
                cout << "Not found" << endl;
            break;
        case 3:
            cout << "Enter the value to be deleted:" << endl;
            cin >> val;
            if (obj.Delete(val))
                cout << "Deleted" << val << endl;
            else
                cout << "Not found!" << endl;
            break;
        case 4:
            obj.Listcount();
            break;
        case 5:
            cout << "Elements from front to rear is:" << endl;
            obj.Displayfr();
            cout << "Elements from rear to front is:" << endl;
            obj.Displayrf();
            break;
        }
    } while (choice != 0);
}
