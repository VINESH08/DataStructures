#include <iostream>
using namespace std;
#define Max 5
class queue
{
    int que[Max];
    int rear, front;

public:
    queue()
    {
        rear = -1;
        front = -1;
    }
    bool isfull()
    {
        if (rear == (Max - 1))
            return true;
        else
            return false;
    }
    bool isempty()
    {
        if (rear == -1)
            return true;
        else
            return false;
    }
    void enque(int data)
    {
        if (isfull())
        {
            cout << "The queue is full!" << endl;
        }
        else
        {
            rear++;
            que[rear] = data;
            if (front == -1)

                front++;
        }
    }
    int deque()
    {
        int dataout = 0;
        if (isempty())
            cout << "the queue is empty!" << endl;
        else
        {
            dataout = que[front];
            if (rear == front)
            {
                rear = -1;
                front = -1;
            }
            else
                front++;
        }
        return dataout;
    }
    int queuefront()
    {
        int dataout = 0;
        if (isempty())

            cout << "no front element" << endl;

        else
            dataout = que[front];
        return dataout;
    }
    int queuerear()
    {
        int dataout = 0;
        if (isempty())
            cout << "no rear element" << endl;
        else
            dataout = que[rear];
        return dataout;
    }
    int queuecount()
    {
        int count = 0;
        if (isempty())

            cout << "length of the queue is 0" << endl;

        else
        {
            count = (rear - front) + 1;
        }
        return count;
    }
};
int main()
{
    queue s;
    int choice, data, a = 0;
    do
    {
        cout << "enter choice" << endl;
        cout << "1.enque element" << endl;
        cout << "2.deque element" << endl;
        cout << "3.queue front " << endl;
        cout << "4.queue rear" << endl;
        cout << "5.queue count" << endl;
        cin >> choice;
        // a = 0;
        if (choice == 1)
        {
            cout << "enter element" << endl;
            cin >> data;
            s.enque(data);
        }
        else if (choice == 2)
        {
            a = s.deque();
            cout << a << endl;
        }
        else if (choice == 3)
        {
            a = s.queuefront();
            cout << a << endl;
        }
        else if (choice == 4)
        {
            a = s.queuerear();
            cout << a << endl;
        }
        else if (choice == 5)
        {
            a = s.queuecount();
            cout << a << endl;
        }
        //a = 0;
    } while (choice != 0);
} //