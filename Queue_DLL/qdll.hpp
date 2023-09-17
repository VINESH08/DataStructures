//.h contains declaration and definetion of the fun,variables.....
#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *nextelement;
    Node *prevelement;
    Node(int value)
    {
        data = value;
        nextelement = nullptr;
        prevelement = nullptr;
    }
};
class Doubleyll
{
private:
    Node *head;
    Node *tail;

public:
    int size;
    Doubleyll();
    bool isEmpty();
    int getHead();
    int getTail();
    int printList();
    int insertTail(int value);
    bool deleteHead();
};