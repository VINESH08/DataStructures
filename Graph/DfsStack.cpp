#include <iostream>
using namespace std;
struct ga;
struct gv
{
    char data;
    bool instack;
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
    int count;
    node *top = NULL;

public:
    graph()
    {
        first = NULL;
        count = 0;
    }
    void insertvertex(char data)
    {
        gv *newvertex = new gv();
        newvertex->data = data;
        newvertex->instack = false;
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
            ya->nextarc = xarc;
        }
    }
    void push(gv *v)
    {
        node *newnode = new node();
        newnode->vertex = v;
        newnode->link = NULL;
        if (top == NULL)
            top = newnode;
        else
        {
            newnode->link = top;
            top = newnode;
        }
    }
    gv *pop()
    {
        node *temp = top;
        gv *t = temp->vertex;
        top = top->link;
        delete temp;
        return t;
    }
    node *Topstack()
    {
        return top;
    }
    void DFS()
    {
        int visitedvertex = 0;
        gv *temp = first;
        push(temp);
        temp->instack = true;
        temp->processed = true;
        cout << temp->data << " ";
        visitedvertex++;
        while (count != visitedvertex)
        {
            ga *arc = Topstack()->vertex->firstarc;
            while (arc != NULL && arc->content->processed == true)
                arc = arc->nextarc;
            if (arc != NULL)
            {
                push(arc->content);
                arc->content->instack = true;
                arc->content->processed = true;
                cout << arc->content->data << " ";
                visitedvertex++;
            }
            else
            {
                temp = pop();
                temp->instack = false;
                if (Topstack() == NULL)
                {
                    temp = temp->nextvertex;
                    while (temp != NULL && temp->processed == true)
                    {
                        temp = temp->nextvertex;
                    }
                    if (temp != NULL)
                    {
                        push(temp);
                        temp->instack = true;
                        temp->processed = true;
                        cout << temp->data << " ";
                        visitedvertex++;
                    }
                }
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
            g.DFS();
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice!";
        }
    } while (ch);
}
