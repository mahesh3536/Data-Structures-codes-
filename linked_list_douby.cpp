#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *prev;
    node *next;
    node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }
};
void inserthead(node *&head, int d)
{

    if (head == NULL)
    {
        node *temp = new node(d);
        head = temp;
    }

    node *temp = new node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void inserttail(node *&tail, int d)
{
    if (tail == NULL)
    {
        node *temp = new node(d);
        tail = temp;
    }

    node *temp = new node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
void insertAtposition(node *&head, node *&tail, int position, int d)
{
    if (position == 1)
    {
        inserthead(head, d);
        return;
    }
    node *temp = head;
    int count = 1;
    while (count < position - 1)
    {
        temp = temp->next;
        count++;
    }
    if (temp->next == NULL)
    {
        inserttail(tail, d);
        return;
    }

    node *insert = new node(d);
    // temp->next=insert;
    insert->next = temp->next;
    temp->next->prev = insert;
    temp->next = insert;
    insert->prev = temp;
}
void print(node *head)
{
    node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()
{
    node *node1 = new node(10);
    node *head = node1;
    node *tail = node1;
    inserthead(head, 11);
    inserttail(tail, 23);
    insertAtposition(head, tail, 2, 45);
    print(head);
}