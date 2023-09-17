#include <iostream>
#include "qdll.h"
using namespace std;
Doubleyll::Doubleyll()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}
bool Doubleyll::isEmpty()
{
    if (head == nullptr)
        return true;
    else
        return false;
}
int Doubleyll::getHead()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    else
        return head->data;
}
int Doubleyll::getTail()
{
    if (!isEmpty())
        return tail->data;
    else

        return -1;
}
int Doubleyll::printList()
{
    if (isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return false;
    }
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->nextelement;
    }
    return true;
}
int Doubleyll::insertTail(int val)
{
    Node *newNode = new Node(val);
    if (isEmpty())
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->nextelement = newNode;
        newNode->prevelement = tail;
        tail = newNode;
    }
    size++;
    return tail->data;
}
bool Doubleyll::deleteHead()
{
    if (isEmpty())
    {
        cout << "Queue is empty no elements can be deleted!" << endl;
        return false;
    }
    else if (size == 1)
    {
        free(head);
        head = NULL;
    }
    else
    {
        Node *temp = head;
        head = head->nextelement;
        head->prevelement = nullptr;
        free(temp);
        temp = NULL;
    }
    size--;
    return true;
}