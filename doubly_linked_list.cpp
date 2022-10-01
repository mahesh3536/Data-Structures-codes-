#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
void deleteAtPosition(Node *&head, Node *&tail, int position)
{
    if (position == 1)
    {
        Node *temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        return;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        bool flag = false;
        while (count < position - 1)
        {
            if (temp->next == NULL ||)
            {
                flag = true;
                break;
            }
            temp = temp->next;
            count++;
        }
        if (flag)
        {
            cout << "You Entered wrong position" << endl;
            return;
        }
        else
        {
            Node *free = temp->next;
            if (free->next == NULL)
                temp->next = NULL;
            else
            {
                temp->next = free->next;
                free->next->prev = temp;
            }
            delete free;
        }
    }
}
void insertAtHead(Node *&head, Node *&tail, int d)
{
    if (head == NULL && tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}
void insertAtTail(Node *&head, Node *&tail, int d)
{
    if (head == NULL && tail == NULL)
    {
        Node *temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else
    {
        Node *temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}
void insertAtPosition(Node *&head, Node *&tail, int d, int position)
{
    if (position == 1)
    {
        insertAtHead(head, tail, d);
        return;
    }
    else
    {
        int count = 1;
        Node *temp = head;
        while (count < position - 1)
        {
            if (temp->next == NULL)
            {
                break;
            }
            temp = temp->next;
            count++;
        }

        if (temp->next == NULL)
        {
            insertAtTail(head, tail, d);
            return;
        }
        else
        {
            Node *insert = new Node(d);
            insert->next = temp->next;
            temp->next->prev = insert;
            temp->next = insert;
            insert->prev = temp;
        }
    }
}
void display(Node *&head)
{
    if (head == NULL)
    {
        return;
    }
    else
    {
        Node *temp = head;
        while (temp != NULL)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
int main()
{
    Node *N = NULL;
    Node *head = N;
    Node *tail = N;
    insertAtHead(head, tail, 5);
    insertAtHead(head, tail, 6);
    insertAtTail(head, tail, 7);
    insertAtPosition(head, tail, 8, 2);
    insertAtPosition(head, tail, 9, 3);
    deleteAtPosition(head, tail, 6);

    display(head);
}