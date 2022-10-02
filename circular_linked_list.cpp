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
int length(Node* &head){
    if(head == NULL){
        return 0;
    }
    Node* temp = head;
    int count = 0;
    do{
      count++;
      temp = temp->next;
    }while(temp!=head);

    return count ;
}
void insertAthead(Node* &head,Node* &tail,int d){
    if(head == NULL && tail == NULL) {
        Node* temp = new Node(d);
        head = temp ;
        tail = temp;
        head ->next = head;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        tail ->next = temp;
        head = temp;
    }
}
void insertAttail(Node* &head,Node* &tail,int d){
    if(head == NULL && tail == NULL){
        Node* temp = new Node(d);
        head = temp ;
        tail = temp;
        head->next = temp;
    }
    else {
        Node* temp = new Node(d);
        temp->next = head;
        tail->next = temp;
        tail = temp;
    }
}
void insertAtposition(Node* &head,Node* &tail,int d,int position){
    int l = length(head);
    int p = position%(l+1);
    if(p==0){
        insertAthead(head,tail,d);
    }
    else {
        int count = 1;
        Node* temp = head;
        bool flag = false;
        while(count < p-1){
            if(temp!=head && count!=1){
                flag = true;
                break;
            }
            temp = temp -> next;
            count++;
        }
        Node* insert = new Node(d);
        insert->next = temp->next;
        temp->next = insert ;
    }
}
void display(Node* &head){
    Node* temp = head ;
    do {
       cout << temp->data << " ";
       temp = temp->next;
    }while(temp!=head);
    cout << endl;
}
int main()
{
    Node* head = NULL ;
    Node* tail = head;
    insertAthead(head,tail,1);
    insertAthead(head,tail,2);
    insertAttail(head,tail,3);
    //cout << length(head) << endl;
    insertAtposition(head,tail,4,3);
    insertAtposition(head,tail,9,5);
    display(head);
}