#include <iostream>
using namespace std;
struct node
{
    int data;
    node *link;
};
struct head
{
    node *front;
    node *rear;
    int count;
};
class Queue
{
    head *headnode;

public:
    bool isEmpty()
    {
        if (headnode->count == 0)
            return true;
        else
            return false;
    }
    void create()
    {
        headnode = new head();
        headnode->front = NULL;
        headnode->rear = NULL;
        headnode->count = 0;
    }
    bool Enqueue(int datain)
    {
        node *newnode = new node();
        newnode->data = datain;
        newnode->link = NULL;
        if (headnode->rear == NULL)
        {
            headnode->front = newnode;
        }
        else
        {
            headnode->rear->link = newnode;
        }
        headnode->rear = newnode;
        (headnode->count)++;
        return true;
    }
    bool Dequeue(int &dout)
    {
        if (isEmpty())
        {
            return false;
        }
        else
        {
            dout = headnode->front->data;
            headnode->front = headnode->front->link;
            if (headnode->front == NULL)
                headnode->rear = NULL;
            (headnode->count)--;
        }
        return true;
    }
    bool getfront(int &dout)
    {
        if (isEmpty())
            return false;
        else
            dout = headnode->front->data;
        return true;
    }
    bool getrear(int &dout)
    {
        if (isEmpty())
        {
            return false;
        }
        else
            dout = headnode->rear->data;
        return true;
    }
    bool destqueue()
    {
        while (headnode->front != NULL)
        {
            node *temp = headnode->front;
            headnode->front = temp->link;
            delete (temp);
        }
        return true;
    }
    void count()
    {
        cout << "Queue count is: " << headnode->count << endl;
    }
};
int main()
{
    Queue q;
    q.create();
    int choice;
    int datain, dataout = 0;
    bool result;
    do
    {
        cout << "enter your choice" << endl;
        cout << "1.Enqueue" << endl;
        cout << "2.Dequeue" << endl;
        cout << "3.Getfront" << endl;
        cout << "4.Getrear" << endl;
        cout << "5.Destroy" << endl;
        cout << "6.count" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "enter the element to be inserted" << endl;
            cin >> datain;
            result = q.Enqueue(datain);
            if (result)
                cout << "inserted successfully" << endl;
            break;
        case 2:
            result = q.Dequeue(dataout);
            if (result)
                cout << dataout << endl;
            else
                cout << "queue is empty" << endl;
            break;
        case 3:
            cout << "The front element is: ";
            result = q.getfront(dataout);
            if (result)
                cout << dataout << endl;
            else
                cout << "queue is empty" << endl;
            break;
        case 4:
            cout << "The rear element is: " << endl;
            result = q.getrear(dataout);
            if (result)
                cout << dataout << endl;
            else
                cout << "queue is empty" << endl;
            break;
        case 5:
            result = q.destqueue();
            if (result)
                cout << "destroyed successfully" << endl;
            break;
        case 6:
            q.count();
            break;
        }
    } while (choice != 0);
}