#include <iostream>
#include <algorithm>
using namespace std;
struct node
{
    int data;
    node *leftchild;
    node *rightchild;
    int height;
};
class Avl
{
public:
    node *parentnode;
    node *newnode;
    node *max, *min;
    int Height(node *Node)
    {
        if (Node == NULL)
            return -1;
        return Node->height;
    }
    node *create(int data)
    {
        newnode = new node();
        newnode->data = data;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
        return newnode;
    }
    node *addNode(node *&root, int val)
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
        root->height = std::max(Height(root->leftchild), Height(root->rightchild)) + 1;
        //  cout << "height of: " << root->data << " is" << root->height << endl;
        return rotate(root);
    }
    node *rotate(node *root)
    {
        // check for left heavy or right heavy
        if (Height(root->leftchild) - Height(root->rightchild) > 1)
        {
            // left heavy
            if (Height(root->leftchild->leftchild) - Height(root->leftchild->rightchild) > 0)
            {
                // left-left case
                return rotateright(root);
            }
            else if (Height(root->leftchild->leftchild) - Height(root->leftchild->rightchild) < 0)
            { // left-right case
                root->leftchild = rotateleft(root->leftchild);
                return rotateright(root);
            }
        }
        if (Height(root->leftchild) - Height(root->rightchild) < -1)
        {
            // right heavy
            if (Height(root->rightchild->leftchild) - Height(root->rightchild->rightchild) < 0)
            {
                // right-right case
                return rotateleft(root);
            }
            else if (Height(root->rightchild->leftchild) - Height(root->rightchild->rightchild) > 0)
            { // right-left case
                root->rightchild = rotateright(root->rightchild);
                return rotateleft(root);
            }
        }
        return root;
    }
    node *rotateleft(node *root)
    {
        node *temp1 = root->rightchild;
        node *temp = temp1->leftchild;
        temp1->leftchild = root;
        root->rightchild = temp;
        root->height = std::max(Height(root->leftchild), Height(root->rightchild)) + 1;
        temp1->height = std::max(Height(temp1->leftchild), Height(temp1->rightchild)) + 1;
        return temp1;
    }
    node *rotateright(node *root)
    {
        node *temp1 = root->leftchild;
        node *temp = temp1->rightchild;
        temp1->rightchild = root;
        root->leftchild = temp;
        root->height = std::max(Height(root->leftchild), Height(root->rightchild)) + 1;
        temp1->height = std::max(Height(temp1->leftchild), Height(temp1->rightchild)) + 1;
        return temp1;
    }
    bool balanced(node *Node)
    {
        if (Node == NULL)
            return true;
        return std::abs(Height(Node->leftchild) - Height(Node->rightchild)) && balanced(Node->leftchild) && balanced(Node->rightchild);
    }
    void parentnodef(node *root, int target)
    {
        while (root != NULL && root->data != target)
        {
            parentnode = root;
            if (root->data > target)
                root = root->leftchild;
            else if (target > root->data)
                root = root->rightchild;
        }
    }
    node *Search(node *root, int target)
    {

        if (root == NULL || root->data == target)
            return root;
        else if (root->data > target)
            return Search(root->leftchild, target);

        return Search(root->rightchild, target);
    }
    node *findMax(node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            max = root;

            if (max->rightchild != NULL)
                max = findMax(max->rightchild);
        }
        return max;
    }
    node *findMin(node *root)
    {
        if (root == NULL)
        {
            cout << "Tree is empty" << endl;
        }
        else
        {
            min = root;
            if (min->leftchild != NULL)
                min = findMin(min->leftchild);
        }
        return min;
    }
};
int main()
{
    Avl tree;
    int choice, n, ele;
    // bool result;
    node *res;
    node *root = NULL;
    do
    {
        cout << "1.Insert element" << endl;
        cout << "2.Search element" << endl;

        cout << "4.Find maximum element" << endl;
        cout << "5.Find minimum element" << endl;
        cout << "6.Check for Balanced Bst" << endl;

        cout << "Enter your choice :" << endl;
        cin >> choice;
        switch (choice)
        {
        case 1:
            cout << "Enter the number of elements to be inserted:" << endl;
            cin >> n;
            cout << "Enter the elements:" << endl;

            while (n--)
            {
                cin >> ele;
                root = tree.addNode(root, ele);
            }

            cout << root->height << endl;
            break;
        case 2:
            cout << "Enter the element to be searched:" << endl;
            cin >> n;
            res = tree.Search(root, n);
            if (res)
                cout << "Found!: " << n << endl;
            else
                cout << "Not found" << endl;
            break;

        case 4:
            res = tree.findMax(root);
            cout << "Maximum element in the tree:" << res->data << endl;
            break;
        case 5:
            res = tree.findMin(root);
            cout << "Minimum element in the tree" << res->data << endl;
            break;
        case 6:
            bool result = tree.balanced(root);
            if (result)
                cout << "The AvL is Balanced" << endl;
            else
                cout << "The AvL is not Balanced" << endl;
        }
    } while (choice != 0);
}
