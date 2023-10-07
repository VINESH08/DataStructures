#include <iostream>
using namespace std;
struct node
{
    int data;
    node *leftchild;
    node *rightchild;
};
class Bst
{
public:
    node *currentnode;
    node *newnode;
    node *max, *min;
    node *create(int data)
    {
        newnode = new node();
        newnode->data = data;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
        return newnode;
    }
    node *addNode(node *root, int val)
    {
        if (root == NULL)
        {
            root = create(val);
        }
        if (val < root->data)
        {
            root->leftchild = addNode(root->leftchild, val);
        }
        else if (val > root->data)
        {
            root->rightchild = addNode(root->rightchild, val);
        }
        return root;
    }
    node *Search(node *root, int target)
    {
        if (root != NULL)
        {
            if (target == root->data)
            {
                currentnode = root;
            }
            else if (target < root->data)
            {
                Search(root->leftchild, target);
            }
            else if (target > root->data)
            {
                Search(root->rightchild, target);
            }
        }
        return currentnode;
    }
    node *findMax(node *root)
    {
        max = root;

        if (max->rightchild != NULL)
            max = findMax(max->rightchild);

        return max;
    }
    node *findMin(node *root)
    {
        min = root;
        if (min->leftchild != NULL)
            min = findMin(min->leftchild);
        return min;
    }
};
int main()
{
    Bst tree;
    int ele;
    node *res;
    node *root = NULL;
    int n, dat;
    cout << "Enter the number of nodes or elements to be inserted: " << endl;
    cin >> n;
    while (n)
    {
        cin >> dat;
        root = tree.addNode(root, dat);
        n--;
    }
    cout << "Enter the element to be searched:" << endl;
    cin >> ele;
    res = tree.Search(root, ele);
    if (res)
        cout << res->data << " Found" << endl;
    else
        cout << "Not found" << endl;
    cout << "Maximum element in the tree:" << endl;
    res = tree.findMax(root);
    cout << res->data << endl;
    cout << "Minimum element in the tree:" << endl;
    res = tree.findMin(root);
    cout << res->data << endl;
}