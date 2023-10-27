#include <iostream>
using namespace std;
struct node
{
    int data;
    node *leftchild;
    node *rightchild;
};
class BinaryTree
{
public:
    int val;
    char left, right;
    node *newnode;
    node *root;

    void insert()
    {
        cout << "Enter the root node:" << endl;
        cin >> val;
        root = new node();
        root->data = val;
        insert(root);
    }
    void insert(node *newnode)
    {
        cout << "Do you want to insert(True/False)left of :" << newnode->data << endl;
        cin >> left;
        if (left == 'y')
        {
            cout << "Enter the left of:" << newnode->data << endl;
            cin >> val;
            newnode->leftchild = new node();
            newnode->leftchild->data = val;
            insert(newnode->leftchild);
        }
        cout << "Do you want to insert(True/False)right of :" << newnode->data << endl;
        cin >> right;
        if (right == 'y')
        {
            cout << "Enter the right of:" << newnode->data << endl;
            cin >> val;
            newnode->rightchild = new node();
            newnode->rightchild->data = val;
            insert(newnode->rightchild);
        }
    }
    void displayP()
    {
        displayP(root);
    }
    void displayP(node *root)
    {
        if (root == NULL)
            return;
        cout << (root->data) << " ";
        displayP(root->leftchild);
        displayP(root->rightchild);
    }
};
int main()
{
    BinaryTree obj;
    obj.insert();
    obj.displayP();
}
