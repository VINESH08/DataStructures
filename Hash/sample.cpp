#include <iostream>
using namespace std;

struct node
{
    int key;
    node *fore;
    node *back;
};

struct list
{
    node *head;
    node *rear;
    int count;
};

class cdll
{
public:
    list *cdllhead;

    cdll()
    {
        cdllhead = new list();
        cdllhead->count = 0;
        cdllhead->head = NULL;
        cdllhead->rear = NULL;
    }
    bool isEmpty()
    {
        if (cdllhead->count == 0)
            return true;
        return false;
    }

    bool searcher(int target, node *&ppre, node *&ploc)
    {
        bool found = false;
        ppre = NULL;
        ploc = cdllhead->head;
        if (isEmpty())
            return found;
        if (ploc->key == target)
        {
            found = true;
            return found;
        }
        if (ploc->key > target)
        {
            found = false;
            return found;
        }
        ppre = ploc;
        ploc = ploc->fore;
        while (ploc != cdllhead->head && target > ploc->key)
        {
            ppre = ploc;
            ploc = ploc->fore;
        }
        if (ploc == cdllhead->head)
        {
            return found;
        }
        else
        {
            if (target == ploc->key)
                found = true;
        }
        return found;
    }

    void insert(int datain)
    {
        node *ppre = NULL;
        node *ploc = NULL;

        // cout<<"hi1"<<endl;
        bool sear = searcher(datain, ppre, ploc);
        // cout<<"hi2"<<endl;
        if (sear)
            cout << "data alreay exist" << endl;
        if (!sear)
        {
            node *newnode = new node();
            newnode->key = datain;
            newnode->back = NULL;
            newnode->fore = NULL;

            if (ppre == NULL)
            {
                // cout << "hi22" << endl;
                if (cdllhead->count == 0)
                {
                    cdllhead->head = newnode;
                    cdllhead->rear = newnode;
                }
                else
                {
                    cdllhead->head->back = newnode;
                    cdllhead->rear->fore = newnode;
                }
                newnode->back = cdllhead->rear;
                newnode->fore = cdllhead->head;
                cdllhead->head = newnode;
            }
            else
            {
                // cout << "hi2" << endl;
                newnode->fore = ploc;
                newnode->back = ppre;
                ppre->fore = newnode;
                if (ploc == cdllhead->head)
                    cdllhead->rear = newnode;
                ploc->back = newnode;
            }
            cdllhead->count++;
        }
    }

    void destroydll()
    {
        node *temp;
        temp = cdllhead->head;
        node *temp1 = NULL;
        if (cdllhead->count != 0)
        {
            temp1 = temp;
            temp = temp->fore;
            delete temp1;
            while (temp != cdllhead->head)
            {
                temp1 = temp;
                temp = temp->fore;
                delete temp1;
            }
        }
        cdllhead->count = 0;
        cdllhead->head = NULL;
        cdllhead->rear = NULL;
    }

    void dispHeadToRear()
    {
        node *pWalker = cdllhead->head;
        if (pWalker != NULL)
        {
            cout << pWalker->key << endl;
            pWalker = pWalker->fore;
        }
        while (pWalker != cdllhead->head)
        {
            cout << pWalker->key << endl;
            pWalker = pWalker->fore;
        }
    }

    void dispRearToFront()
    {
        node *pWalker = cdllhead->rear;
        if (pWalker != NULL)
        {
            cout << pWalker->key << endl;
            pWalker = pWalker->back;
        }
        while (pWalker != cdllhead->rear)
        {
            cout << pWalker->key << endl;
            pWalker = pWalker->back;
        }
    }
};
int main()
{
    cdll l1;
    int choice, valin;
    node *ppre;
    node *ploc;
    do
    {
        cout << "1.To insert" << endl;
        cout << "2.To Search" << endl;
        cout << "3.To delete" << endl;
        cout << "4.Display head to rear" << endl;
        cout << "5.Display rear to head" << endl;

        cout << "Enter your choice" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:

            cout << "Enter the value" << endl;
            cin >> valin;
            l1.insert(valin);
            break;
        case 2:
            cout << "Enter the value to be searched:" << endl;
            cin >> valin;
            if (l1.searcher(valin, ppre, ploc))
                cout << "Found: " << valin << endl;
            else
                cout << "Not found" << endl;
            break;

        case 4:
            cout << "Elements from front to rear is:" << endl;
            l1.dispHeadToRear();
            cout << "Elements from rear to front is:" << endl;
            l1.dispRearToFront();
            break;
        }
    } while (choice != 0);

    return 0;
}