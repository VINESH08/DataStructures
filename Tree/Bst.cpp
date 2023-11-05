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
class Bst
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
        cout << "height of: " << root->data << " is" << root->height << endl;
        return root;
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
    node *Delete(node *&root, int target)
    {
        if (root != NULL)
        {
            // node *searchnode = Search(root, target);
            parentnodef(root, target);
            node *searchnode = Search(root, target);
            if (searchnode != NULL)
            {
                if (searchnode->leftchild == NULL && searchnode->rightchild == NULL)
                { // leafnode to be deleted...
                    if (searchnode->data == root->data)
                    {
                        root = NULL;
                        delete root;
                        // root = NULL;
                    }
                    else if (searchnode->data < parentnode->data)
                    {
                        parentnode->leftchild = NULL;
                        delete searchnode;
                    }
                    else if (searchnode->data > parentnode->data)
                    {
                        parentnode->rightchild = NULL;
                        delete searchnode;
                    }
                    return root;
                }
                // node to be deleted has only right child/subtree.
                else if (searchnode->leftchild == NULL)
                {
                    if (root->data == searchnode->data)
                    {
                        root = searchnode->rightchild;
                        searchnode->rightchild = NULL;
                        delete searchnode;
                    }
                    else if (searchnode->data < parentnode->data)
                    {
                        parentnode->leftchild = searchnode->rightchild;
                        searchnode->rightchild = NULL;
                        delete searchnode;
                    }
                    else if (searchnode->data > parentnode->data)
                    {
                        parentnode->rightchild = searchnode->rightchild;
                        searchnode->rightchild = NULL;
                        delete searchnode;
                    }
                    return root;
                }
                // node to be deleted has only left child/subtree.
                else if (searchnode->rightchild == NULL)
                {
                    if (searchnode->data == root->data)
                    {
                        root = searchnode->leftchild;
                        searchnode->leftchild = NULL;
                        delete searchnode;
                    }
                    else if (searchnode->data > parentnode->data)
                    {
                        parentnode->rightchild = searchnode->leftchild;
                        searchnode->leftchild = NULL;
                        delete searchnode;
                    }
                    else if (searchnode->data < parentnode->data)
                    {
                        parentnode->leftchild = searchnode->leftchild;
                        searchnode->leftchild = NULL;
                        delete searchnode;
                    }
                    return root;
                }
                else
                {
                    node *replace = findMax(searchnode->leftchild);
                    int temp = replace->data;
                    Delete(root, temp);
                    searchnode->data = replace->data;
                }
            }
            else
                cout << "element not found" << endl;
        }
        return root;
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
    Bst tree;
    int ele, choice, n;
    // bool result;
    node *res;
    node *root = NULL;
    do
    {
        cout << "1.Insert element" << endl;
        cout << "2.Search element" << endl;
        cout << "3.Delete element" << endl;
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
        case 3:
            cout << "Enter the element to be deleted:" << endl;
            cin >> n;
            res = tree.Delete(root, n);
            if (res)
                cout << "Deleted: " << n << "Successfully" << endl;
            else
                cout << "Element not found" << endl;
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
                cout << "The Bst is Balanced" << endl;
            else
                cout << "The Bst is not Balanced" << endl;
        }
    } while (choice != 0);
}
