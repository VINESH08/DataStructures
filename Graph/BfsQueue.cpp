#include <iostream>
using namespace std;
struct ga;
struct gv
{
    char data;
    bool inqueue;
    bool processed;
    gv *nextvertex;
    ga *firstarc;
};
struct ga
{
    gv *content;
    ga *nextarc;
};
struct node
{
    gv *vertex;
    node *link;
};
class graph
{
    gv *first;
    int count, qcount;
    node *front;
    node *rear;

public:
    graph()
    {
        first = NULL;
        count = 0;
        qcount = 0;
        front = NULL;
        rear = NULL;
    }
    void insertvertex(char data)
    {
        gv *newvertex = new gv();
        newvertex->data = data;
        newvertex->inqueue = false;
        newvertex->processed = false;
        newvertex->firstarc = NULL;
        newvertex->nextvertex = NULL;
        if (first == NULL)
            first = newvertex;
        else
        {
            gv *t = first;
            while (t->nextvertex != NULL)
                t = t->nextvertex;
            t->nextvertex = newvertex;
        }
        count++;
        cout << "Vertex inserted!" << endl;
    }
    bool insertarc(char x, char y)
    {
        gv *xtemp, *ytemp = NULL;
        gv *xt = first;
        gv *yt = first;
        while (xt != NULL && xt->data != x)
            xt = xt->nextvertex;
        while (yt != NULL && yt->data != y)
            yt = yt->nextvertex;
        if (xt == NULL || yt == NULL)
            return false;
        else
        {
            xtemp = xt;
            ytemp = yt;
        }
        // for xtemp
        ga *xarc = new ga();
        xarc->content = ytemp;
        xarc->nextarc = NULL;
        if (xtemp->firstarc == NULL)
            xtemp->firstarc = xarc;
        else
        {
            ga *xa = xtemp->firstarc;
            while (xa->nextarc != NULL)
                xa = xa->nextarc;
            xa->nextarc = xarc;
        }
        // for ytemp
        ga *yarc = new ga();
        yarc->content = xtemp;
        yarc->nextarc = NULL;
        if (ytemp->firstarc == NULL)
            ytemp->firstarc = yarc;
        else
        {
            ga *ya = ytemp->firstarc;
            while (ya->nextarc != NULL)
                ya = ya->nextarc;
            ya->nextarc = yarc;
        }
        return true;
    }
    void enqueue(gv *v)
    {
        node *newnode = new node();
        newnode->vertex = v;
        newnode->link = NULL;
        if (front == NULL)
        {
            front = newnode;
            rear = newnode;
        }
        else
        {
            rear->link = newnode;
            rear = newnode;
        }
        qcount++;
    }
    gv *dequeue()
    {
        node *temp = front;
        gv *t = front->vertex;
        front = front->link;
        delete temp;
        qcount--;
        return t;
    }
    void BFS()
    {
        gv *temp = first;
        enqueue(temp);
        while (qcount != 0)
        {
            gv *dequeued = dequeue();
            cout << dequeued->data << " ";
            dequeued->inqueue = false;
            dequeued->processed = true;
            ga *arc = dequeued->firstarc;
            while (arc != NULL)
            {
                if (arc->content->processed != true && arc->content->inqueue != true)
                {
                    enqueue(arc->content);
                    arc->content->inqueue = true;
                }
                arc = arc->nextarc;
            }
        }
        cout << endl;
    }
};
int main()
{
    graph g;
    int ch;
    char x, y;
    do
    {
        cout << "1-Insert Vertex, 2-Insert Edge, 3-Breadth first search,0-Exit\n";
        cout << "Enter choice: ";
        cin >> ch;
        switch (ch)
        {
        case 1:
            cout << "Enter character to insert: ";
            cin >> x;
            g.insertvertex(x);
            break;
        case 2:
            cout << "Enter characters to add edge: ";
            cin >> x >> y;
            if (g.insertarc(x, y))
                cout << "Edge inserted between " << x << " and " << y << "." << endl;
            else
                cout << "Either one or both vertices not present in graph.\n";
            break;
        case 3:
            g.BFS();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (ch);
}
