#include <iostream>
#include <cstring>
using namespace std;
struct node
{
    string name;
    string department;
    int rollno;
    node *leftchild;
    node *rightchild;
};
class Student
{
public:
    node *parentnode, *newnode;
    node *create(string Name, string Department, int Rollno)
    {
        newnode = new node();
        newnode->name = Name;
        newnode->department = Department;
        newnode->rollno = Rollno;
        newnode->leftchild = NULL;
        newnode->rightchild = NULL;
        return newnode;
    }
    node *addnode(node *&root, string Name, string Department, int Rollno)
    {
        if (root == NULL)
        {
            root = create(Name, Department, Rollno);
        }
        if (Name < root->name)
        {
            root->leftchild = addnode(root->leftchild, Name, Department, Rollno);
        }
        else if (Name > root->name)
        {
            root->rightchild = addnode(root->rightchild, Name, Department, Rollno);
        }
        return root;
    }
    void display(node *root)
    {
        if (root != NULL)
        {
            display(root->leftchild);
            cout << root->name << " ";
            display(root->rightchild);
        }
    }
};
int main()
{
    Student s;
    node *root = NULL;
    string Name;
    string Department;
    int Rollno;
    for (int i = 0; i < 3; i++)
    {
        cout << "Enter name" << endl;
        cin >> Name;
        cout << "Enter Department" << endl;
        cin >> Department;
        cout << "Enter the rollno" << endl;
        cin >> Rollno;
        root = s.addnode(root, Name, Department, Rollno);
    }
    s.display(root);
}