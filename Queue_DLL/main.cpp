#include <iostream>
#include "qdll.hppq"
using namespace std;
class myqueue
{
private:
    Doubleyll items; //create an object for the class Doubleyll definded in qdll.cpp
public:
    int isempty()
    {
        return items.size == 0;
    }
    int getfront()
    {
        if (!items.isEmpty())
        {
            cout << "front element is:" << items.getHead() << endl;
            return items.getHead();
        }
        else
        {
            items.getHead();
            return -1;
        }
    }
    int gettail()
    {
        if (!items.isEmpty())
        {
            cout << "the tail element is" << items.getTail() << endl;
            return items.getTail();
        }
        else
        {
            return -1;
        }
    }
    int getsize()
    {
        return items.size;
    }
    int enqueue(int val)
    {
        return items.insertTail(val);
    }
    int dequeue()
    {
        return items.deleteHead();
    }
    bool showqueue()
    {
        return items.printList();
    }
};
int main()
{
    myqueue q;
    for (int i = 1; i <= 5; i++)
    {
        q.enqueue(i); // inserting data in queue
        q.showqueue();
    }

    q.getfront();
    q.gettail();
    q.getsize(); // size of queue

    while (q.isempty() == false)
    {
        q.dequeue();
        // cout<< "Dequeue() " << endl;
    }
    q.showqueue();

    return 0;
}