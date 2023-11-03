#include <iostream>
using namespace std;
struct node
{
    int data;
    node *leftchild;
    node *rightchild;
};
struct Queuenode
{
    node *treenode;
    Queuenode *next;
};
class BinaryTree
{
public:
    int val;
    char left, right;
    node *newnode;
    node *root;
    Queuenode *front, *rear = NULL;
    void enqueue(node *tnode)
    {
        Queuenode *newnode = new Queuenode();
        newnode->treenode = tnode;
        newnode->next = NULL;
        if (rear == NULL)
        {
            front = rear = newnode;
            return;
        }
        rear->next = newnode;
        rear = newnode;
    }
    node *dequeue()
    {
        if (front == nullptr)
        {
            return NULL;
        }
        Queuenode *temp = front;
        node *result = front->treenode;
        front = front->next;
        if (front == nullptr)
            rear = nullptr;
        delete temp;
        return result;
    }
    void BFS()
    {
        BFS(root);
    }
    void BFS(node *root)
    {
        node *currentnode = root;
        while (currentnode != NULL)
        {
            cout << currentnode->data << " ";
            if (currentnode->leftchild != NULL)
            {
                enqueue(currentnode->leftchild);
            }
            if (currentnode->rightchild != NULL)
            {
                enqueue(currentnode->rightchild);
            }
            if (front != NULL)
                currentnode = dequeue();
            else
                currentnode = NULL;
        }
    }
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
    // obj.displayP();
    obj.BFS();
}
