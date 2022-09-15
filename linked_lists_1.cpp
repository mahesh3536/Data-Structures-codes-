#include<bits/stdc++.h>
using namespace std; 
class node{
    
    public:
    int data;
    node* next;
    
    node(int d){
        this->data=d;
        this->next=NULL;
        
    }
};
void inserttail(node* &tail,int d){
    node* temp=new node(d);
    tail->next=temp;
    temp->next=NULL;
    tail=temp;
}
void inserthead(node* &head,int d){
    node* temp=new node(d);
    temp->next=head;
    //head->next=NULL;
    head=temp;
}
void insertAtposition(node* &head,node* &tail,int position,int d){
    if (position==1)
    {
        inserthead(head,d);
        return;
    }

   
    
    node* temp=head;
    int count=1;
    while (count<position-1)
    {
        temp=temp->next;
        count++;
    }
    if (temp->next==NULL)
    {
       inserttail(tail,d);
       return;
    }
    
    node* insert=new node(d);
    //temp->next=insert;
    insert->next=temp->next;
    temp->next=insert;
}

void print(node* &head){
    node* temp=head;
    while (temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int main()
{
    node* node1 = new node(10);
    print(node1);
    node* head = node1;
    node* tail = node1;
    inserttail(tail,12);
    insertAtposition(head,tail,1,15);
    inserthead(head,23);
    print(head);
    
}
