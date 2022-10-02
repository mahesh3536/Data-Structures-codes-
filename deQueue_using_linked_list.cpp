#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *prev;
    Node(int val)
    {
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
    }
};
class deQueue
{
public:
    Node *f;
    Node *r;
    deQueue()
    {
        f = NULL;
        r = NULL;
    }
    int front()
    {
        if (f == NULL && r == NULL)
        {
            cout << "deQueue is Empty" << endl;
            return -1;
        }
        return f->data;
    }
    int rear()
    {
        if (f == NULL && r == NULL)
        {
            cout << "deQueue is Empty" << endl;
        }
        return r->data;
    }
    void push_front(int d)
    {

        Node *temp = new Node(d);
        if (f == NULL && r == NULL)
        {
            f = temp;
            r = temp;
        }
        else
        {
            temp->next = f;
            f->prev = temp;
            f = temp;
        }
    }
    void push_rear(int d)
    {
        Node *temp = new Node(d);
        if (f == NULL && r == NULL)
        {
            f = temp;
            r = temp;
        }
        else
        {
            r->next = temp;
            temp->prev = r;
            r = temp;
        }
    }
    int pop_front()
    {
        if (f == NULL && r == NULL)
        {
            cout << "deQueue is Empty" << endl;
            return -1;
        }
        int p = f->data;
        Node *temp = f;
        f = f->next;
        f->prev = NULL;
        delete temp;
        return p;
    }
    int pop_rear()
    {
        if (f == NULL && r == NULL)
        {
            cout << "deQueue is Empty" << endl;
            return -1;
        }
        int p = r->data;
        Node *temp = r;
        r = r->prev;
        r->next = NULL;
        delete temp;
        return p;
    }
};
int main()
{
    deQueue Q;
    Q.push_rear(4);
    Q.push_front(5);
    Q.push_rear(6);
    cout << Q.pop_rear() << endl;
    cout << Q.rear() << endl;
}