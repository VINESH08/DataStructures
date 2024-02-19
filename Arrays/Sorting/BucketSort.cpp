#include <iostream>
using namespace std;
struct node
{
    float data;
    node *link;
};
struct Listhead
{
    int count;
    node *head;
};
class BucketSort
{
private:
    Listhead **hashtabel;
    int size;

public:
    BucketSort(int n)
    {
        size = n;
        hashtabel = new Listhead *[n];
        for (int i = 0; i < n; i++)
        {
            hashtabel[i] = new Listhead();
            hashtabel[i]->count = 0;
            hashtabel[i]->head = NULL;
        }
    }
    void insert(float val, int siz)
    {
        node *ploc = NULL;
        node *ppre = NULL;
        int k = val * siz;
        search(ppre, ploc, val, k);
        node *newnode = new node();
        newnode->data = val;
        newnode->link = NULL;

        if (ppre == NULL)
        {
            if (hashtabel[k]->count == 0)
            {
                hashtabel[k]->head = newnode;
            }
            else
            {
                newnode->link = hashtabel[k]->head;
                hashtabel[k]->head = newnode;
            }
        }
        else
        {
            newnode->link = ploc;
            ppre->link = newnode;
        }
        hashtabel[k]->count++;

        // else{
        // node*temp=hashtabel[k]->head;
        // while(temp->link!=NULL){
        // temp=temp->link;
        // }
        // temp->link=newnode;
        // hashtabel[k]->count++;
        // }
    }
    void search(node *&ppre, node *&ploc, float target, int k)
    {
        ppre = NULL;
        ploc = hashtabel[k]->head;
        while (ploc != NULL && target > ploc->data)
        {
            ppre = ploc;
            ploc = ploc->link;
        }
    }
    void display()
    {
        for (int i = 0; i < size; i++)
        {
            node *temp = hashtabel[i]->head;
            cout << "For index:" << i << "   ";
            while (temp)
            {
                cout << temp->data << " ";
                temp = temp->link;
            }
            cout << endl;
        }
    }
};
int main()
{
    int n, ele;
    float val;
    cout << "Enter the size of the hashtabel" << endl;
    cin >> n;
    BucketSort obj(n);
    cout << "Enter the number of values to be inserted" << endl;
    cin >> ele;
    cout << "Enter the elements" << endl;
    for (int i = 0; i < ele; i++)
    {
        cin >> val;
        obj.insert(val, ele);
    }
    obj.display();
}
