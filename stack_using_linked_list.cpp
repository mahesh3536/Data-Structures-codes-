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
class stack
{
public:
  Node *top;
  stack()
  {
    top = NULL;
  }
  bool empty()
  {
    if (top == NULL)
    {
      return true;
    }
    else
      return false;
  }
  int peek()
  {
    if (top == NULL)
    {
      cout << "stack is empty" << endl;
      return 0;
    }
    else
    {
      return top->data;
    }
  }
  void pop()
  {
    if (empty())
    {
      cout << "stack is empty" << endl;
    }

    else
    {
      top = top->next;
    }
  }
  void push(int element)
  {
    Node *n = new Node(element);
    if (empty())
    {
      top = n;
    }
    else
    {
      Node *temp = top;
      top = n;
      n->next = temp;
    }
  }
};
int main()
{
  stack st;

  st.push(5);
  st.push(6);
  st.push(7);
  cout << st.empty() << endl;
  cout << st.peek() << endl
       << st.top->next->data;
}