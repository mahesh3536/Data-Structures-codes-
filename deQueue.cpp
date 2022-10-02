#include <iostream>
using namespace std;
class deQueue
{
public:
    int *arr;
    int f;
    int r;
    int size;
    deQueue(int d)
    {
        this->size = d;
        arr = new int[d];
        this->f = -1;
        this->r = -1;
    }
    bool isFull()
    {
        if (r == -1 && f == size - 1)
            return true;
        else if ((r + 1) % size == f && r != -1)
            return true;
        else
            return false;
    }
    bool isEmpty()
    {
        if (f == -1 && r == -1)
            return true;
        else
            return false;
    }
    void push_front(int val)
    {
        if (r == 0 && f == size - 1)
            cout << "deQueue is Full" << endl;
        else if ((r + 1) % size == f && r != -1)
            cout << "deQueue is Full" << endl;
        else if (f == -1 && r == -1)
        {
            f = 0;
            r = 0;
            arr[f] = val;
        }
        else if (f == 0 && r != size - 1)
        {
            f = size - 1;
        }
        else
            f--;
        arr[f] = val;
    }
    void push_rear(int val)
    {
        if (r == 0 && f == size - 1)
            cout << "deQueue is Full" << endl;
        else if ((r + 1) % size == f)
            cout << "deQueue is Full" << endl;
        else if (f == -1 && r == -1)
        {
            f = 0;
            r = 0;
        }
        else if (r == size - 1 && f != 0)
            r = 0;
        else
            r++;
        arr[r] = val;
    }
    int pop_front()
    {
        if (f == -1 && r == -1)
        {
            cout << "deQueue is empty" << endl;
            return -1;
        }
        else if (f == r)
        {
            int p = arr[f];
            f = -1;
            r = -1;
            return p;
        }
        else if (f == size - 1)
        {
            int p = arr[f];
            f = 0;
            return p;
        }
        else
        {
            int p = arr[f];
            f++;
            return p;
        }
    }
    int pop_rear()
    {
        if (f == -1 && r == -1)
        {
            cout << "deQueue is Empty" << endl;
            return -1;
        }
        else if (f == r)
        {
            int p = arr[r];
            f = -1;
            r = -1;
            return p;
        }
        else if (r == 0)
        {
            int p = arr[r];
            r = size - 1;
            return p;
        }
        else
        {
            int p = arr[r];
            r--;
            return p;
        }
    }
    int front()
    {
        if (f == -1 && r == -1)
        {
            cout << "deQueue is empty" << endl;
            return -1;
        }
        else
        {
            return arr[f];
        }
    }
    int rear()
    {
        if (f == -1 && r == -1)
        {
            cout << "deQueue is empty" << endl;
            return -1;
        }

        else
            return arr[r];
    }
};
int main()
{
    deQueue Q(3);
  
}