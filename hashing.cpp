#include<bits/stdc++.h>
using namespace std;
class Node{
   public:
   int data;
   Node* next;
   Node(int d){
    this->data = d;
    this->next = NULL;
   }
   Node(){
    this->data = -1;
    this->next = NULL;
   }
};
void insertAtTail(Node* &head,Node* &tail,int d){
   if(head==NULL && tail==NULL){
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
   }
   else if(head->data == -1 && tail->data==-1){
    Node* temp = new Node(d);
    head = temp;
    tail = temp;
   }
   else {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
   }
}
void display(Node* head){
    Node* curr=head;
    while(curr!=NULL){
        cout << curr->data << " ";
        curr=curr->next;
    }
    cout << endl;
}
int main(){
   vector<Node*> head(10);
   vector<Node*> tail(10);
   tail = head;
   //cout << head[0]->data << endl;
   Node* p = NULL;
  for(int i = 0;i<10;i++){
     p = new Node();
     head[i]=p;
     tail[i]=head[i];
  }
  int size ;
  cout << "Enter size : " ;
  cin>>size;
  vector<int> list(size);
  cout << "Enter list of elments which you want to hash : " << endl;
  for(int i = 0;i<size;i++){
    cin>>list[i];
  }
  for(int i = 0;i<size;i++){
    int r = list[i]%10;
    insertAtTail(head[r],tail[r],list[i]);
  }
  for(int i = 0;i<10;i++){
    cout << i << "->";
    display(head[i]);
  }
}