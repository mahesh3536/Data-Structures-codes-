#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
    }
};
class Queue
{
public:
    Node *front;
    Node *rear;
    Queue()
    {
        this->front = NULL;
        this->rear = NULL;
    }
    bool isEmpty()
    {
        if (front == rear && front == NULL)
        {
            return true;
        }
        else
            return false;
    }
    void enQueue(int d)
    {
        Node *temp = new Node(d);
        if (front == rear && front == NULL)
        {
            front = temp;
            rear = temp;
        }
        else
        {
            rear->next = temp;
            rear = temp;
            rear->next = front;
        }
    }
    int f()
    {
        if (front == rear && front == NULL)
        {
            return -1;
        }
        else
            return front->data;
    }
    int deQueue()
    {
        if (front == rear && front == NULL)
        {
            cout << "Queue is empty" << endl;
            return -1;
        }
        else if (front == rear)
        {
            int temp = front->data;
            front = NULL;
            rear = NULL;
            return temp;
        }
        else
        {
            int temp = front->data;
            front = front->next;
            rear->next = front;
            return temp;
        }
    }
    int back()
    {
        if (front == rear && front == NULL)
        {
            return -1;
        }
        else
            return rear->data;
    }
    void display()
    {
        if (isEmpty())
        {
            cout << "Queue is Empty" << endl;
        }
        else
        {
            Node *temp = front;
            do
            {
                cout << temp->data << " "
                     << " ";
                temp = temp->next;
            } while (temp != front);
            cout << endl;
        }
    }
};
int main()
{
    Queue *Q = new Queue();
    int val;
    do
    {
        cout << "1.Enter 1 for isEmpty" << endl;
        cout << "2.Enter 2 for Display" << endl;
        cout << "3.Enter 3 for enQueue" << endl;
        cout << "4.Enter 4 for deQueue" << endl;
        cout << "5.Enter 5 for front element" << endl;
        cout << "6.Enter 6 for rear element" << endl;
        cout << "7.Enter 7 for exit" << endl;
        cin >> val;
        switch (val)
        {
        case 1:
        {
            if (Q->isEmpty())
                cout << "Queue is empty" << endl;
            else
                cout << "Queue is not empty" << endl;
        }
        break;
        case 2:
        {
            cout << "Queue elements are : " << endl;
            Q->display();
        }
        break;
        case 3:
        {

            int data;
            cout << "Enter data for enQueue : ";
            cin >> data;
            Q->enQueue(data);
            cout << "enQueue done" << endl;
        }
        break;
        case 4:
        {
            if (Q->isEmpty())
                cout << "Queue is Empty" << endl;
            else
            {
                cout << "DeQueue element of Queue is : ";
                cout << Q->deQueue() << endl;
            }
        }
        break;
        case 5:
        {
            if (Q->isEmpty())
                cout << "Queue is Empty" << endl;
            else
            {
                cout << "Front element of Queue is : " << Q->f() << endl;
            }
        }
        break;
        case 6:
        {
            if (Q->isEmpty())
                cout << "Queue is Empty" << endl;
            else
            {
                cout << "Rear element of Queue is : " << Q->back() << endl;
            }
        }
        }
    } while (val != 7);
}